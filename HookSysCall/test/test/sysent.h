//
//  sysent.h
//  test
//
//  Created by 五千年木 on 2018/12/24.
//  Copyright © 2018年 osxkernel. All rights reserved.
//

#ifndef sysent_h
#define sysent_h

#include "define.h"
#include <libkern/libkern.h>
/*
 * System call prototypes.
 *
 * Derived from FreeBSD's syscalls.master by Landon Fuller, original RCS IDs below:
 *
 * $FreeBSD: src/sys/sys/sysproto.h,v 1.216 2008/01/08 22:01:26 jhb Exp $
 * created from FreeBSD: src/sys/kern/syscalls.master,v 1.235 2008/01/08 21:58:15 jhb
 */

/*
 * Modified by me to support yosemite
 */

typedef int32_t sy_call_t(struct proc *, void *, int *);
typedef int32_t sy_call64_t(struct proc *, void *, int64_t *);

typedef void sy_munge_t(void *); // For OS X 10.10 and above
typedef void sy_munge_t_mavericks(const void *, void *); // For OS X 10.9

#define PAD_(t) (sizeof(uint64_t) <= sizeof(t) ? 0 : sizeof(uint64_t) - sizeof(t))

#if BYTE_ORDER == LITTLE_ENDIAN
#   define PADL_(t)        0
#   define PADR_(t)        PAD_(t)
#else
#   define PADL_(t)        PAD_(t)
#   define PADR_(t)        0
#endif

#define PAD_ARG_(arg_type, arg_name) \
char arg_name##_l_[PADL_(arg_type)]; arg_type arg_name; char arg_name##_r_[PADR_(arg_type)];

#define PAD_ARG_8

/** ptrace request */
#define PT_DENY_ATTACH 31

#define    SYS_syscall        0
#define    SYS_exit           1
#define    SYS_fork           2
#define    SYS_read           3
#define    SYS_write          4
#define    SYS_open           5
#define    SYS_close          6
#define    SYS_wait4          7
/* 8  old creat */
#define    SYS_link           9
#define    SYS_unlink         10
/* 11  old execv */
#define    SYS_chdir          12
#define    SYS_fchdir         13
#define    SYS_mknod          14
#define    SYS_chmod          15
#define    SYS_chown          16
/* 17  old break */
#define    SYS_getfsstat      18
/* 19  old lseek */
#define    SYS_getpid         20
/* 21  old mount */
/* 22  old umount */
#define    SYS_setuid         23
#define    SYS_getuid         24
#define    SYS_geteuid        25
#define    SYS_ptrace         26
#define    SYS_recvmsg        27
#define    SYS_sendmsg        28
#define    SYS_recvfrom       29
#define    SYS_accept         30
#define    SYS_getpeername    31
#define    SYS_getsockname    32
#define    SYS_access         33
#define    SYS_chflags        34
#define    SYS_fchflags       35
#define    SYS_sync           36
#define    SYS_kill           37
/* 38  old stat */
#define    SYS_getppid        39
/* 40  old lstat */
#define    SYS_dup            41
#define    SYS_pipe           42
#define    SYS_getegid        43
#define    SYS_profil         44
/* 45  old ktrace */
#define    SYS_sigaction      46
#define    SYS_getgid         47
#define    SYS_sigprocmask    48
#define    SYS_getlogin       49
#define    SYS_setlogin       50
#define    SYS_acct           51
#define    SYS_sigpending     52
#define    SYS_sigaltstack    53
#define    SYS_ioctl          54
#define    SYS_reboot         55
#define    SYS_revoke         56
#define    SYS_symlink        57
#define    SYS_readlink       58
#define    SYS_execve         59
#define    SYS_umask          60
#define    SYS_chroot         61
/* 62  old fstat */
/* 63  used internally , reserved */
/* 64  old getpagesize */
#define    SYS_msync          65
#define    SYS_vfork          66
/* 67  old vread */
/* 68  old vwrite */
/* 69  old sbrk */
/* 70  old sstk */
/* 71  old mmap */
/* 72  old vadvise */
#define    SYS_munmap         73
#define    SYS_mprotect       74
#define    SYS_madvise        75
/* 76  old vhangup */
/* 77  old vlimit */
#define    SYS_mincore        78
#define    SYS_getgroups      79
#define    SYS_setgroups      80
#define    SYS_getpgrp        81
#define    SYS_setpgid        82
#define    SYS_setitimer      83
/* 84  old wait */
#define    SYS_swapon         85
#define    SYS_getitimer      86
/* 87  old gethostname */
/* 88  old sethostname */
#define    SYS_getdtablesize  89
#define    SYS_dup2           90
/* 91  old getdopt */
#define    SYS_fcntl          92
#define    SYS_select         93
/* 94  old setdopt */
#define    SYS_fsync          95
#define    SYS_setpriority    96
#define    SYS_socket         97
#define    SYS_connect        98
/* 99  old accept */
#define    SYS_getpriority    100
/* 101  old send */
/* 102  old recv */
/* 103  old sigreturn */
#define    SYS_bind           104
#define    SYS_setsockopt     105
#define    SYS_listen         106
/* 107  old vtimes */
/* 108  old sigvec */
/* 109  old sigblock */
/* 110  old sigsetmask */
#define    SYS_sigsuspend     111
/* 112  old sigstack */
/* 113  old recvmsg */
/* 114  old sendmsg */
/* 115  old vtrace */
#define    SYS_gettimeofday   116
#define    SYS_getrusage      117
#define    SYS_getsockopt     118
/* 119  old resuba */
#define    SYS_readv          120
#define    SYS_writev         121
#define    SYS_settimeofday   122
#define    SYS_fchown         123
#define    SYS_fchmod         124
/* 125  old recvfrom */
#define    SYS_setreuid       126
#define    SYS_setregid       127
#define    SYS_rename         128
/* 129  old truncate */
/* 130  old ftruncate */
#define    SYS_flock          131
#define    SYS_mkfifo         132
#define    SYS_sendto         133
#define    SYS_shutdown       134
#define    SYS_socketpair     135
#define    SYS_mkdir          136
#define    SYS_rmdir          137
#define    SYS_utimes         138
#define    SYS_futimes        139
#define    SYS_adjtime        140
/* 141  old getpeername */
#define    SYS_gethostuuid    142
/* 143  old sethostid */
/* 144  old getrlimit */
/* 145  old setrlimit */
/* 146  old killpg */
#define    SYS_setsid         147
/* 148  old setquota */
/* 149  old qquota */
/* 150  old getsockname */
#define    SYS_getpgid        151
#define    SYS_setprivexec    152
#define    SYS_pread          153
#define    SYS_pwrite         154
#define    SYS_nfssvc         155
/* 156  old getdirentries */
#define    SYS_statfs         157
#define    SYS_fstatfs        158
#define    SYS_unmount        159
/* 160  old async_daemon */
#define    SYS_getfh          161
/* 162  old getdomainname */
/* 163  old setdomainname */
/* 164  */
#define    SYS_quotactl       165
/* 166  old exportfs */
#define    SYS_mount          167
/* 168  old ustat */
#define    SYS_csops          169
/* 170  old table */
/* 171  old wait3 */
/* 172  old rpause */
#define    SYS_waitid         173
/* 174  old getdents */
/* 175  old gc_control */
#define    SYS_add_profil     176
/* 177  */
/* 178  */
/* 179  */
#define    SYS_kdebug_trace   180
#define    SYS_setgid         181
#define    SYS_setegid        182
#define    SYS_seteuid        183
#define    SYS_sigreturn      184
#define    SYS_chud           185
/* 186  */
#define    SYS_fdatasync      187
#define    SYS_stat           188
#define    SYS_fstat          189
#define    SYS_lstat          190
#define    SYS_pathconf       191
#define    SYS_fpathconf      192
/* 193  */
#define    SYS_getrlimit      194
#define    SYS_setrlimit      195
#define    SYS_getdirentries  196
#define    SYS_mmap           197
/* 198  __syscall */
#define    SYS_lseek          199
#define    SYS_truncate       200
#define    SYS_ftruncate      201
#define    SYS___sysctl       202
#define    SYS_mlock          203
#define    SYS_munlock        204
#define    SYS_undelete       205
#define    SYS_ATsocket       206
#define    SYS_ATgetmsg       207
#define    SYS_ATputmsg       208
#define    SYS_ATPsndreq      209
#define    SYS_ATPsndrsp      210
#define    SYS_ATPgetreq      211
#define    SYS_ATPgetrsp      212
/* 213  Reserved for AppleTalk */
/* 214  */
/* 215  */
#define    SYS_mkcomplex      216
#define    SYS_statv          217
#define    SYS_lstatv         218
#define    SYS_fstatv         219
#define    SYS_getattrlist    220
#define    SYS_setattrlist    221
#define    SYS_getdirentriesattr 222
#define    SYS_exchangedata   223
/* 224  old checkuseraccess / fsgetpath ( which moved to 427 ) */
#define    SYS_searchfs       225
#define    SYS_delete         226
#define    SYS_copyfile       227
#define    SYS_fgetattrlist   228
#define    SYS_fsetattrlist   229
#define    SYS_poll           230
#define    SYS_watchevent     231
#define    SYS_waitevent      232
#define    SYS_modwatch       233
#define    SYS_getxattr       234
#define    SYS_fgetxattr      235
#define    SYS_setxattr       236
#define    SYS_fsetxattr      237
#define    SYS_removexattr    238
#define    SYS_fremovexattr   239
#define    SYS_listxattr      240
#define    SYS_flistxattr     241
#define    SYS_fsctl          242
#define    SYS_initgroups     243
#define    SYS_posix_spawn    244
#define    SYS_ffsctl         245
/* 246  */
#define    SYS_nfsclnt        247
#define    SYS_fhopen         248
/* 249  */
#define    SYS_minherit       250
#define    SYS_semsys         251
#define    SYS_msgsys         252
#define    SYS_shmsys         253
#define    SYS_semctl         254
#define    SYS_semget         255
#define    SYS_semop          256
/* 257  */
#define    SYS_msgctl         258
#define    SYS_msgget         259
#define    SYS_msgsnd         260
#define    SYS_msgrcv         261
#define    SYS_shmat          262
#define    SYS_shmctl         263
#define    SYS_shmdt          264
#define    SYS_shmget         265
#define    SYS_shm_open       266
#define    SYS_shm_unlink     267
#define    SYS_sem_open       268
#define    SYS_sem_close      269
#define    SYS_sem_unlink     270
#define    SYS_sem_wait       271
#define    SYS_sem_trywait    272
#define    SYS_sem_post       273
#define    SYS_sem_getvalue   274
#define    SYS_sem_init       275
#define    SYS_sem_destroy    276
#define    SYS_open_extended  277
#define    SYS_umask_extended 278
#define    SYS_stat_extended  279
#define    SYS_lstat_extended 280
#define    SYS_fstat_extended 281
#define    SYS_chmod_extended 282
#define    SYS_fchmod_extended 283
#define    SYS_access_extended 284
#define    SYS_settid         285
#define    SYS_gettid         286
#define    SYS_setsgroups     287
#define    SYS_getsgroups     288
#define    SYS_setwgroups     289
#define    SYS_getwgroups     290
#define    SYS_mkfifo_extended 291
#define    SYS_mkdir_extended 292
#define    SYS_identitysvc    293
#define    SYS_shared_region_check_np 294
/* 295  old shared_region_map_np */
#define    SYS_vm_pressure_monitor 296
#define    SYS_psynch_rw_longrdlock 297
#define    SYS_psynch_rw_yieldwrlock 298
#define    SYS_psynch_rw_downgrade 299
#define    SYS_psynch_rw_upgrade 300
#define    SYS_psynch_mutexwait 301
#define    SYS_psynch_mutexdrop 302
#define    SYS_psynch_cvbroad 303
#define    SYS_psynch_cvsignal 304
#define    SYS_psynch_cvwait  305
#define    SYS_psynch_rw_rdlock 306
#define    SYS_psynch_rw_wrlock 307
#define    SYS_psynch_rw_unlock 308
#define    SYS_psynch_rw_unlock2 309
#define    SYS_getsid         310
#define    SYS_settid_with_pid 311
#define    SYS_psynch_cvclrprepost 312
#define    SYS_aio_fsync      313
#define    SYS_aio_return     314
#define    SYS_aio_suspend    315
#define    SYS_aio_cancel     316
#define    SYS_aio_error      317
#define    SYS_aio_read       318
#define    SYS_aio_write      319
#define    SYS_lio_listio     320
/* 321  old __pthread_cond_wait */
#define    SYS_iopolicysys    322
#define    SYS_process_policy 323
#define    SYS_mlockall       324
#define    SYS_munlockall     325
/* 326  */
#define    SYS_issetugid      327
#define    SYS___pthread_kill 328
#define    SYS___pthread_sigmask 329
#define    SYS___sigwait      330
#define    SYS___disable_threadsignal 331
#define    SYS___pthread_markcancel 332
#define    SYS___pthread_canceled 333
#define    SYS___semwait_signal 334
/* 335  old utrace */
#define    SYS_proc_info      336
#define    SYS_sendfile       337
#define    SYS_stat64         338
#define    SYS_fstat64        339
#define    SYS_lstat64        340
#define    SYS_stat64_extended 341
#define    SYS_lstat64_extended 342
#define    SYS_fstat64_extended 343
#define    SYS_getdirentries64 344
#define    SYS_statfs64       345
#define    SYS_fstatfs64      346
#define    SYS_getfsstat64    347
#define    SYS___pthread_chdir 348
#define    SYS___pthread_fchdir 349
#define    SYS_audit          350
#define    SYS_auditon        351
/* 352  */
#define    SYS_getauid        353
#define    SYS_setauid        354
#define    SYS_getaudit       355
#define    SYS_setaudit       356
#define    SYS_getaudit_addr  357
#define    SYS_setaudit_addr  358
#define    SYS_auditctl       359
#define    SYS_bsdthread_create 360
#define    SYS_bsdthread_terminate 361
#define    SYS_kqueue         362
#define    SYS_kevent         363
#define    SYS_lchown         364
#define    SYS_stack_snapshot 365
#define    SYS_bsdthread_register 366
#define    SYS_workq_open     367
#define    SYS_workq_kernreturn 368
#define    SYS_kevent64       369
#define    SYS___old_semwait_signal 370
#define    SYS___old_semwait_signal_nocancel 371
#define    SYS_thread_selfid  372
/* 373  */
/* 374  */
/* 375  */
/* 376  */
/* 377  */
/* 378  */
/* 379  */
#define    SYS___mac_execve   380
#define    SYS___mac_syscall  381
#define    SYS___mac_get_file 382
#define    SYS___mac_set_file 383
#define    SYS___mac_get_link 384
#define    SYS___mac_set_link 385
#define    SYS___mac_get_proc 386
#define    SYS___mac_set_proc 387
#define    SYS___mac_get_fd   388
#define    SYS___mac_set_fd   389
#define    SYS___mac_get_pid  390
#define    SYS___mac_get_lcid 391
#define    SYS___mac_get_lctx 392
#define    SYS___mac_set_lctx 393
#define    SYS_setlcid        394
#define    SYS_getlcid        395
#define    SYS_read_nocancel  396
#define    SYS_write_nocancel 397
#define    SYS_open_nocancel  398
#define    SYS_close_nocancel 399
#define    SYS_wait4_nocancel 400
#define    SYS_recvmsg_nocancel 401
#define    SYS_sendmsg_nocancel 402
#define    SYS_recvfrom_nocancel 403
#define    SYS_accept_nocancel 404
#define    SYS_msync_nocancel 405
#define    SYS_fcntl_nocancel 406
#define    SYS_select_nocancel 407
#define    SYS_fsync_nocancel 408
#define    SYS_connect_nocancel 409
#define    SYS_sigsuspend_nocancel 410
#define    SYS_readv_nocancel 411
#define    SYS_writev_nocancel 412
#define    SYS_sendto_nocancel 413
#define    SYS_pread_nocancel 414
#define    SYS_pwrite_nocancel 415
#define    SYS_waitid_nocancel 416
#define    SYS_poll_nocancel  417
#define    SYS_msgsnd_nocancel 418
#define    SYS_msgrcv_nocancel 419
#define    SYS_sem_wait_nocancel 420
#define    SYS_aio_suspend_nocancel 421
#define    SYS___sigwait_nocancel 422
#define    SYS___semwait_signal_nocancel 423
#define    SYS___mac_mount    424
#define    SYS___mac_get_mount 425
#define    SYS___mac_getfsstat 426
#define    SYS_fsgetpath      427
#define    SYS_audit_session_self 428
#define    SYS_audit_session_join 429
#define    SYS_fileport_makeport 430
#define    SYS_fileport_makefd 431
#define    SYS_audit_session_port 432
#define    SYS_pid_suspend    433
#define    SYS_pid_resume     434
#define    SYS_pid_hibernate  435
#define    SYS_pid_shutdown_sockets 436
/* 437  old shared_region_slide_np */
#define    SYS_shared_region_map_and_slide_np 438
#define SYS_kas_info       439
#define    SYS_MAXSYSCALL    440


//typedef int32_t	sy_call_t (struct proc *, void *, int *);
//typedef void	sy_munge_t (const void *, void *);

// 10.8 and prior */
//struct sysent {
//    int16_t		sy_narg;            /* number of arguments */
//    int8_t		reserved;           /* unused value */
//    int8_t		sy_flags;           /* call flags */
//    sy_call_t	*sy_call;           /* implementing function */
//    sy_munge_t	*sy_arg_munge32;	/* munge system call arguments for 32-bit processes */
//    sy_munge_t	*sy_arg_munge64;	/* munge system call arguments for 64-bit processes */
//    int32_t		sy_return_type;     /* return type */
//    uint16_t	sy_arg_bytes;       /* The size of all arguments for 32-bit system calls, in bytes */
//};

// 10.9
//struct sysent_mavericks {           /* system call table */
//    sy_call_t	*sy_call;           /* implementing function */
//    sy_munge_t	*sy_arg_munge32;    /* system call arguments munger for 32-bit process */
//    sy_munge_t	*sy_arg_munge64;    /* system call arguments munger for 64-bit process */
//    int32_t		sy_return_type;     /* system call return types */
//    int16_t		sy_narg;            /* number of args */
//    uint16_t	sy_arg_bytes;       /* Total size of arguments in bytes for
//                                     * 32-bit system calls
//                                     */
//};

// 10.10+
struct sysent_yosemite {            /* system call table */
    sy_call_t	*sy_call;           /* implementing function */
    sy_munge_t	*sy_arg_munge32;    /* system call arguments munger for 32-bit process */
    int32_t		sy_return_type;     /* system call return types */
    int16_t		sy_narg;            /* number of args */
    uint16_t	sy_arg_bytes;       /* Total size of arguments in bytes for
                                     * 32-bit system calls
                                     */
};

// 10.12
struct sysent_sierra {            /* system call table */
    sy_call_t	*sy_call;           /* implementing function */
    sy_munge_t	*sy_arg_munge32;    /* system call arguments munger for 32-bit process */
    int32_t		sy_return_type;     /* system call return types */
    int16_t		sy_narg;            /* number of args */
    uint16_t	sy_arg_bytes;       /* Total size of arguments in bytes for
                                     * 32-bit system calls
                                     */
};


#define MACH_MSG_TRAP 31
#define MACH_MSG_OVERWRITE_TRAP 32

// 10.8
typedef struct {
    int                 mach_trap_arg_count;
    void*               mach_trap_function;
} mach_trap_t;

// 10.9+
typedef struct {
    int                 mach_trap_arg_count; /* Number of trap arguments (Arch independant) */
    void*               mach_trap_function;
    void*               mach_trap_arg_munge32; /* system call argument munger routine for 32-bit */
    int                 mach_trap_u32_words; /* number of 32-bit words to copyin for U32 */
    void*               mach_trap_name;
} mach_trap_mavericks_t;


//---------------------





struct sysent {          // system call table, OS X 10.10 and above
    sy_call_t *sy_call;    // implementing function
    sy_munge_t *sy_arg_munge32; // system call arguments munger for 32-bit process
    int32_t  sy_return_type; // system call return types
    int16_t  sy_narg;      // number of args
    uint16_t sy_arg_bytes; // Total size of args in bytes for 32-bit system calls
};

struct sysent_mavericks {// system call table, OS X 10.9
    sy_call_t *sy_call;    // implementing function
    sy_munge_t_mavericks *sy_arg_munge32; // arguments munger for 32-bit process
    sy_munge_t_mavericks *sy_arg_munge64; // arguments munger for 64-bit process
    int32_t  sy_return_type; // system call return types
    int16_t  sy_narg;      // number of args
    uint16_t sy_arg_bytes; // Total size of args in bytes for 32-bit system calls
};

struct sysent * find_sysent_table(void);
void* find_mach_tables(void);



#endif /* sysent_h */
