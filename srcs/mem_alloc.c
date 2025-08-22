#include <stdlib.h>
#include "mem_utils.h"

void	*__wrap_malloc(size_t size)
{
	void	*res;

	res = __real_malloc(size);
	if (!res)
		return (mem_error());
	mem_add_new_block(res, size);
	return (res);
}

void	*__wrap_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	void			*res;
	size_t			i;

	res = __real_malloc(size * count);
	if (!res)
		return (mem_error());
	ptr = res;
	i = -1;
	while (++i < size * count)
		ptr[i] = '\0';
	mem_add_new_block(res, size * count);
	return (res);
}

void	*__wrap_realloc(void *old_data, size_t new_size)
{
	size_t					i;
	void					*res;
	unsigned char			*new_ptr;
	size_t					old_size;
	unsigned char *const	old_ptr = old_data;

	res = __real_malloc(new_size);
	if (!res)
		return (mem_error());
	i = -1;
	new_ptr = res;
	old_size = mem_find_size(old_data);
	while (++i < (old_size * (old_size < new_size)) + (new_size
			* (new_size < old_size)))
		new_ptr[i] = old_ptr[i];
	mem_add_new_block(res, new_size);
	return (res);
}
