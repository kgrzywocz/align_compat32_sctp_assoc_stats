#pragma once

#include "sctp_assoc_stats_fromKernel.h"
#include "sctp_assoc_stats_compat32.h"

void align_compat32_sctp_assoc_stats(void *sctp_assoc_stats)
{
	struct sctp_assoc_stats* p64 = sctp_assoc_stats;
	struct sctp_assoc_stats_compat32* p32 = sctp_assoc_stats;

	p32->sas_assoc_id   				= p64->sas_assoc_id;
	p32->sas_obs_rto_ipaddr.ss_family   = p64->sas_obs_rto_ipaddr.ss_family;
	memcpy(p32->sas_obs_rto_ipaddr.__data, p64->sas_obs_rto_ipaddr.__data, sizeof(p32->sas_obs_rto_ipaddr.__data));
	p32->sas_maxrto		  				= p64->sas_maxrto;
	p32->sas_isacks  					= p64->sas_isacks;
	p32->sas_osacks  					= p64->sas_osacks;
	p32->sas_opackets  					= p64->sas_opackets;
	p32->sas_ipackets  					= p64->sas_ipackets;
	p32->sas_rtxchunks  				= p64->sas_rtxchunks;
	p32->sas_outofseqtsns  				= p64->sas_outofseqtsns;
	p32->sas_idupchunks  				= p64->sas_idupchunks;
	p32->sas_gapcnt   					= p64->sas_gapcnt;
	p32->sas_ouodchunks   				= p64->sas_ouodchunks;
	p32->sas_iuodchunks   				= p64->sas_iuodchunks;
	p32->sas_oodchunks   				= p64->sas_oodchunks;
	p32->sas_iodchunks   				= p64->sas_iodchunks;
	p32->sas_octrlchunks   				= p64->sas_octrlchunks;
	p32->sas_ictrlchunks   				= p64->sas_ictrlchunks;
}