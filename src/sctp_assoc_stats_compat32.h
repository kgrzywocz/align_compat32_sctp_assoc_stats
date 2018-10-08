
struct __kernel_sockaddr_storage_compat32 {
	__kernel_sa_family_t	ss_family;		/* address family */
	/* Following field(s) are implementation specific */
	char		__data[_K_SS_MAXSIZE - sizeof(unsigned short)];
				/* space to achieve desired size, */
				/* _SS_MAXSIZE value minus size of ss_family */
} __attribute__ ((packed,aligned(4)));	/* force desired alignment */


struct sctp_assoc_stats_compat32 {
	int32_t	sas_assoc_id;    /* Input */
					 /* Transport of observed max RTO */
	struct __kernel_sockaddr_storage_compat32 sas_obs_rto_ipaddr;
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
} __attribute__ ((packed,aligned(4)));
