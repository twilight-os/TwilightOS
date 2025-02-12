/*
 *	Twilight OS
 *	(c) 2025, Jel9
 */
#include <twsup.h>

extern "C" {
    int _fltused = 0;
    void __chkstk(void)
    {
    }
}

extern "C"
VOID *
memset(
    VOID *dst,
    INT val,
    SIZE_T len
)
{
    CHAR *dst8 = ( CHAR * )dst;
    while ( len-- )
    {
        *dst8++ = ( CHAR )val;
    }
    return dst;
}

INT 
StrCompare(
    PCCHAR str1, 
    PCCHAR str2
) 
{
    while ( *str1 && ( *str1 == *str2 ) ) 
    {
        str1++;
        str2++;
    }
    return *(PUCHAR)str1 - *(PUCHAR)str2;
}
