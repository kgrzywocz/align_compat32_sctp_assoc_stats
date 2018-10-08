////////////////////////////////////////////////////////////////////////////////
//  Structures from kernel
////////////////////////////////////////////////////////////////////////////////


struct sockaddr {
	unsigned short	sa_family;	/* address family, AF_xxx	*/
	char		sa_data[14];	/* 14 bytes of protocol address	*/
};

#define _K_SS_MAXSIZE	128	/* Implementation specific max size */
#define _K_SS_ALIGNSIZE	(__alignof__ (struct sockaddr *))

typedef unsigned short __kernel_sa_family_t;

struct __kernel_sockaddr_storage {
	__kernel_sa_family_t	ss_family;		/* address family */
	/* Following field(s) are implementation specific */
	char		__data[_K_SS_MAXSIZE - sizeof(unsigned short)];
				/* space to achieve desired size, */
				/* _SS_MAXSIZE value minus size of ss_family */
} __attribute__ ((aligned(_K_SS_ALIGNSIZE)));	/* force desired alignment */


#define sockaddr_storage __kernel_sockaddr_storage

struct sctp_assoc_stats {
	int32_t	sas_assoc_id;    /* Input */
					 /* Transport of observed max RTO */
	struct sockaddr_storage sas_obs_rto_ipaddr;
	uint64_t		sas_maxrto;      /* Maximum Observed RTO for period */
	uint64_t		sas_isacks;	 /* SACKs received */
	uint64_t		sas_osacks;	 /* SACKs sent */
	uint64_t		sas_opackets;	 /* Packets sent */
	uint64_t		sas_ipackets;	 /* Packets received */
	uint64_t		sas_rtxchunks;   /* Retransmitted Chunks */
	uint64_t		sas_outofseqtsns;/* TSN received > next expected */
	uint64_t		sas_idupchunks;  /* Dups received (ordered+unordered) */
	uint64_t		sas_gapcnt;      /* Gap Acknowledgements Received */
	uint64_t		sas_ouodchunks;  /* Unordered data chunks sent */
	uint64_t		sas_iuodchunks;  /* Unordered data chunks received */
	uint64_t		sas_oodchunks;	 /* Ordered data chunks sent */
	uint64_t		sas_iodchunks;	 /* Ordered data chunks received */
	uint64_t		sas_octrlchunks; /* Control chunks sent */
	uint64_t		sas_ictrlchunks; /* Control chunks received */
} ;
