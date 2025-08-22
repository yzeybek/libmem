#include <stdlib.h>
#include "mem_utils.h"

void	*mem_absorb(void *addr)
{
	mem_add_new_block(addr, 1);
	return (addr);
}

void	__wrap_free(void *ptr)
{
	(void)ptr;
}

void	mem_free(void)
{
	mem_clear_block(mem_add_new_block(NULL, 0)->head);
}

void	__wrap_exit(int status)
{
	mem_free();
	__real_exit(status);
}

int	__wrap_main(int argc, char **argv, char **envp)
{
	int	res;

	res = __real_main(argc, argv, envp);
	mem_free();
	return (res);
}
