#pragma once

#pragma warning(disable:4200)
#pragma warning(disable:4201)
#pragma warning(disable:4213)
#pragma warning(disable:4214)
#pragma warning(disable:4701)
#pragma warning(disable:4053)
#pragma warning(disable:4152)

#include <twbase.h>
#include <intrin.h>

extern unsigned char DbgFont[];

VOID
DbgPrint(
    PCSTR format,
    ...
);

VOID
DbgInitialize( 
    multiboot_tag_framebuffer_t *framebuffer
);

SIZE_T
StrLenght(PCSTR str);