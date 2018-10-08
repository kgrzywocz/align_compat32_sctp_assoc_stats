#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "align_compat32_sctp_assoc_stats.h"

int main()
{
	printf("  Size of sctp_assoc_stats       = %ld\n", sizeof(struct sctp_assoc_stats));
	printf("  Size of sctp_assoc_stats_compat32 = %ld\n", sizeof(struct sctp_assoc_stats_compat32));
	printf("  Size of sockaddr_storage       = %ld\n", sizeof(struct sockaddr_storage));
	printf("  Alignment of sctp_assoc_stats  = %ld\n", __alignof__(struct sctp_assoc_stats));
	printf("  Alignment of sctp_assoc_stats_compat32  = %ld\n", __alignof__(struct sctp_assoc_stats_compat32));

	struct sctp_assoc_stats stat64;

	stat64.sas_assoc_id = 1;					 
	stat64.sas_obs_rto_ipaddr.ss_family = 17;
	stat64.sas_obs_rto_ipaddr.__data[0] = 18;
	stat64.sas_maxrto = 2;
	stat64.sas_isacks = 3;
	stat64.sas_osacks = 4;
	stat64.sas_opackets = 5;
	stat64.sas_ipackets = 6;
	stat64.sas_rtxchunks = 7;
	stat64.sas_outofseqtsns = 8;
	stat64.sas_idupchunks = 9;
	stat64.sas_gapcnt = 10;
	stat64.sas_ouodchunks = 11;
	stat64.sas_iuodchunks = 12;
	stat64.sas_oodchunks = 13;
	stat64.sas_iodchunks = 14;
	stat64.sas_octrlchunks = 15;
	stat64.sas_ictrlchunks = 16;

	align_compat32_sctp_assoc_stats(&stat64);

	struct sctp_assoc_stats_compat32 *stat32 = (void*) &stat64;
	assert( stat32->sas_assoc_id == 1); 
	assert( stat32->sas_obs_rto_ipaddr.ss_family == 17);
	assert( stat32->sas_obs_rto_ipaddr.__data[0] == 18);
	assert( stat32->sas_maxrto == 2);
	assert( stat32->sas_isacks == 3);
	assert( stat32->sas_osacks == 4);
	assert( stat32->sas_opackets == 5);
	assert( stat32->sas_ipackets == 6);
	assert( stat32->sas_rtxchunks == 7);
	assert( stat32->sas_outofseqtsns == 8);
	assert( stat32->sas_idupchunks == 9);
	assert( stat32->sas_gapcnt == 10);
	assert( stat32->sas_ouodchunks == 11);
	assert( stat32->sas_iuodchunks == 12);
	assert( stat32->sas_oodchunks == 13);
	assert( stat32->sas_iodchunks == 14);
	assert( stat32->sas_octrlchunks == 15);
	assert( stat32->sas_ictrlchunks == 16);

	printf("\nTest was succesful!\n");

	return 0;
}