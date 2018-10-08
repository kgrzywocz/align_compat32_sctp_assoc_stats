#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <unistd.h>
#include <signal.h>

#include <netinet/in.h>
#include <netinet/sctp.h>
#include <arpa/inet.h>

#define MSG_SIZE    1000
#define PORT        10000


int serv_sock_fd;
int client_sock_fd;

void closeSockets()
{
    if(close(serv_sock_fd) < 0)
        perror("serv_sock_fd close");
    if(close(client_sock_fd) < 0)
        perror("client_sock_fd close");
}

void handle_signal(int signum)
{
    switch(signum)
    {
        case SIGINT:
            closeSockets();
            exit(0);
            break;  
        default: exit(0);
            break;
    }
}
void setSignalHandler()
{
    struct sigaction sig_handler;
    sig_handler.sa_handler = handle_signal;
    sig_handler.sa_flags = 0;
    if(sigaction(SIGINT, &sig_handler, NULL) == -1)
        perror("sigaction");
}

int createServerSctpSocket()
{
    int fd;
    if((fd = socket(AF_INET, SOCK_SEQPACKET, IPPROTO_SCTP)) < 0)
        perror("socket");
    return fd;
}
int createClientSctpSocket()
{
    int fd;
    if((fd = socket(AF_INET, SOCK_STREAM, IPPROTO_SCTP)) < 0)
        perror("socket");
    return fd;
}

void startServerSock(int serv_sock_fd)
{
    int reuse = 1;
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    inet_aton("127.0.0.1", &(addr.sin_addr));
    addr.sin_port = htons(PORT);

    if(setsockopt(serv_sock_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int))< 0)
        perror("setsockopt");  
    if(bind(serv_sock_fd, (struct sockaddr*)&addr, sizeof(struct sockaddr)) < 0)
        perror("bind");

    if(listen(serv_sock_fd, 2) < 0)
        perror("listen");

}

void connectClientToServer(int client_sock_fd)
{
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    inet_aton("127.0.0.1", &(addr.sin_addr));
    addr.sin_port = htons(PORT);

    if(connect(client_sock_fd, (struct sockaddr*)&addr, sizeof(struct sockaddr)) < 0)
    {
        perror("connect");
        close(client_sock_fd);
        exit(0);
    }
}

int sendData(int sock_fd)
{
    char buffer_client[MSG_SIZE];
    int nBytes;
    if( (nBytes=send(sock_fd, buffer_client, MSG_SIZE, 0)) == -1)
        perror("write");
    return nBytes;
}
int reciveData(int sock_fd)
{
    int flags = 0;
    char buffer_server[MSG_SIZE];
    return sctp_recvmsg(sock_fd, buffer_server, MSG_SIZE, NULL, 0, NULL, &flags);
}

int main()
{
    setSignalHandler();
    
    serv_sock_fd = createServerSctpSocket();
    startServerSock(serv_sock_fd);
   
    client_sock_fd = createClientSctpSocket();
    connectClientToServer(client_sock_fd);

    int bytes_client=sendData(client_sock_fd);
    printf("Sent %d bytes\n",bytes_client);
    int bytes_server = reciveData(serv_sock_fd);
    printf("Received %d bytes\n", bytes_server);      

//test
    struct sctp_assoc_stats l_sctpAssocStats;
	memset(&l_sctpAssocStats, 0, sizeof(l_sctpAssocStats));
	int len = (sizeof l_sctpAssocStats);
	getsockopt(client_sock_fd, SOL_SCTP, SCTP_GET_ASSOC_STATS, &l_sctpAssocStats, &len);
	printf("packets sent: %lld\npackets recv: %lld\n", l_sctpAssocStats.sas_opackets, l_sctpAssocStats.sas_ipackets);

    closeSockets();
}
