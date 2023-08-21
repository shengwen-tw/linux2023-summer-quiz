#ifndef __LINUX_COMMON_H__
#define __LINUX_COMMON_H__

#define container_of(ptr, type, member) \
    ((type *) ((char *) (ptr) - (offsetof(type, member))))

#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

#ifndef __always_inline
#define __always_inline inline
#endif

#define __WRITE_ONCE(x, val)                  \
    do {                                      \
        *(volatile typeof(x) *) &(x) = (val); \
    } while (0)

#define WRITE_ONCE(x, val)    \
    do {                      \
        __WRITE_ONCE(x, val); \
    } while (0)

#endif
