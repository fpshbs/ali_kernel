#ifndef _FALLOC_H_
#define _FALLOC_H_

#define FALLOC_FL_KEEP_SIZE	0x01 /* default is extend size */

/* We set FALLOC_FL_EXPOSE_STALE_DATA to 0x04 because, in current upstream,
 * FALLOC_FL_PUNCH_HOLE is 0x02.
 */
#define FALLOC_FL_EXPOSE_STALE_DATA	0x04 /* expose stale data */

#ifdef __KERNEL__

/*
 * Space reservation ioctls and argument structure
 * are designed to be compatible with the legacy XFS ioctls.
 */
struct space_resv {
	__s16		l_type;
	__s16		l_whence;
	__s64		l_start;
	__s64		l_len;		/* len == 0 means until end of file */
	__s32		l_sysid;
	__u32		l_pid;
	__s32		l_pad[4];	/* reserved area */
};

#define FS_IOC_RESVSP		_IOW('X', 40, struct space_resv)
#define FS_IOC_RESVSP64		_IOW('X', 42, struct space_resv)

#endif /* __KERNEL__ */

#endif /* _FALLOC_H_ */
