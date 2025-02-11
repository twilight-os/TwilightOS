#include <twsup.h>

#define SSFN_CONSOLEBITMAP_CONTROL
#define SSFN_CONSOLEBITMAP_TRUECOLOR
#define SSFN_MAXLINES 1024 * 8
#include <ssfn.h>

#define PRINTF_ALIAS_STANDARD_FUNCTION_NAMES_SOFT 1
#include <printf/printf.h>

VOID
DbgPrint(
    PCSTR format,
    ...
)
{
    va_list args;
    va_start(args, format);
    vprintf_(format, args);
    va_end(args);
}

VOID putchar_(
    char c
) 
{
    ssfn_putc( c );
}

VOID
DbgInitialize( 
    multiboot_tag_framebuffer_t *framebuffer
)
{
    ssfn_src = (ssfn_font_t *)(DbgFont);
    ssfn_dst.ptr = (unsigned char *)framebuffer->framebuffer_addr;
    ssfn_dst.w = framebuffer->framebuffer_width;
    ssfn_dst.h = framebuffer->framebuffer_height;
    ssfn_dst.p = framebuffer->framebuffer_pitch;
    ssfn_dst.x = ssfn_dst.y = 0;
    ssfn_dst.fg = 0xFFFFFFFF;
}