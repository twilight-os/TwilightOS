/*
 *	Twilight OS
 *	(c) 2025, Jel9
 */
#include <twsup.h>

extern "C"
VOID
KiSystemStartup(
    UINT magic,
    ULONG64_PTR addr
)
{
    multiboot_tag_t* tag, * last;
    UINT size;

    multiboot_tag_mmap_t* tagmmap;
    multiboot_tag_framebuffer_t* tagfb;
    multiboot_tag_cmdline_t* tagcmd;

    while (*((VOLATILE PUCHAR)0x558)) {}; *((VOLATILE PUCHAR)0x558) = 1;

    if ( magic != MULTIBOOT2_BOOTLOADER_MAGIC )
    {
        __halt( );
    }

    if ( addr & 7 )
    {
        __halt( );
    }

    size = ((multiboot_info_t*)addr)->total_size;
    for (tag = (multiboot_tag_t*)(addr + 8), last = (multiboot_tag_t*)(addr + size);
        tag < last && tag->type != MULTIBOOT_TAG_TYPE_END;
        tag = (multiboot_tag_t*)((PUCHAR)tag + ((tag->size + 7) & ~7))
    )
    {
        switch (tag->type) {
        case MULTIBOOT_TAG_TYPE_CMDLINE:
            tagcmd = ( multiboot_tag_cmdline_t* )tag;
            break;
        case MULTIBOOT_TAG_TYPE_MMAP:
            tagmmap = ( multiboot_tag_mmap_t* )tag;
            break;
        case MULTIBOOT_TAG_TYPE_FRAMEBUFFER:
            tagfb = ( multiboot_tag_framebuffer_t* )tag;
            break;
        }
    }
    tag = (multiboot_tag_t*)((PUCHAR)tag + ((tag->size + 7) & ~7));

    for ( 
        UINT i = 0; i < tagfb->framebuffer_height; i++ 
    )
    {
        for ( 
            UINT j = 0; j < tagfb->framebuffer_width; j++ 
        )
        {
            ((PUINT)tagfb->framebuffer_addr)[i * tagfb->framebuffer_width + j] = 0xfb607f;
        }
    }


    DbgInitialize( tagfb );

    DbgPrint( "Twilight OS" );

    if ( StrCompare(tagcmd->string, "debug") == 0 )
    {
        DbgPrint(" (Debug)\n");
	}
	else {
		DbgPrint( "\n" );
	}
   
    DbgPrint( "(c) 2025, Jel9\n" );

    __halt( );
}