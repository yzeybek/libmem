# libmem

Library that allows u to handle memory leaks with only compile flags:

*/path/to/libmem.a -Wl,--wrap=malloc,--wrap=free,--wrap=exit,--wrap=realloc,--wrap=calloc,--wrap=main*
