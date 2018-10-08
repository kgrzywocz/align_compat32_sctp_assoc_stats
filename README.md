# Problem:
On 64bit kernel ELF32bit gets inproper value of `SCTP_GET_ASSOC_STATS` (call `getsockopt` on SCTP socket) due to different `struct sctp_assoc_stats` alignment (mostly because of different `_K_SS_ALIGNSIZE`).

# Steps to reproduce

## Kernel config needed to reproduce the problem on x86_64:
~~~
CONFIG_IA32_EMULATION=y
CONFIG_NET=y
CONFIG_INET=y
CONFIG_IPV6=y
CONFIG_IP_SCTP=y
~~~

## Binary:
```
make testELF
```

## Output:
```
./testELF
Sent 1000 bytes
Received 1000 bytes
packets sent: 12884901888
packets recv: 12884901888
```

# Solution
My proposition is to realign struct at the end of `sctp_getsockopt_assoc_stats(..)` when called in compat mode see patch for details

# Testing
This solution was tested on:
- qemu-system-x86_64 (64bit and 32bit ELF)
<!--
- qemu-system-i386
- qemu-system-arm
- qemu-system-aarch64
- qemu-system-mips
- qemu-system-mips64
- native ubuntu x86_64 (64bit and 32bit ELF)
-->