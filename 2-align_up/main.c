#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#define PRINT_ALIGN_UP(addr, n) \
    printf("align_up(%d, %d) = %ld\n", addr, n, align_up(addr, n))

static inline uintptr_t align_up(uintptr_t sz, size_t alignment)
{
    uintptr_t mask = alignment - 1;
    if ((alignment & mask) == 0) { /* power of two? */
        return (sz + mask) & ~mask;
    }
    return (((sz + mask) / alignment) * alignment);
}

int main(void)
{
    PRINT_ALIGN_UP(120, 4);

    PRINT_ALIGN_UP(121, 4);
    PRINT_ALIGN_UP(122, 4);
    PRINT_ALIGN_UP(123, 4);
    PRINT_ALIGN_UP(124, 4);

    PRINT_ALIGN_UP(125, 4);
    PRINT_ALIGN_UP(126, 4);
    PRINT_ALIGN_UP(127, 4);
    PRINT_ALIGN_UP(128, 4);

    PRINT_ALIGN_UP(129, 4);
    PRINT_ALIGN_UP(130, 4);
    PRINT_ALIGN_UP(131, 4);
    PRINT_ALIGN_UP(132, 4);

    return 0;
}
