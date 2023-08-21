#ifndef __LINUX_COMMON_H__
#define __LINUX_COMMON_H__

#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)

#define __always_inline inline

#define __WRITE_ONCE(x, val)                                            \
do {                                                                    \
        *(volatile typeof(x) *)&(x) = (val);                            \
} while (0)

#define WRITE_ONCE(x, val)                                              \
do {                                                                    \
        __WRITE_ONCE(x, val);                                           \
} while (0)

#endif
