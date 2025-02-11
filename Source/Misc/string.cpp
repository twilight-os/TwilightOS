#include <twsup.h>

extern "C"
VOID *
memset(
    VOID *dst,
    INT val,
    SIZE_T len
)
{
    CHAR *dst8 = (CHAR *)dst;
    while (len--)
    {
        *dst8++ = (CHAR)val;
    }
    return dst;
}