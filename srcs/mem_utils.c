#include <stdlib.h>
#include <unistd.h>
#include "mem_utils.h"

t_mem_block	*mem_add_new_block(void *data, size_t size)
{
	static t_mem_block	*head;
	t_mem_block			*new;
	t_mem_block			*node;

	new = __real_malloc(sizeof(t_mem_block));
	if (!new)
		return (mem_error());
	new->data = data;
	new->size = size;
	new->head = &head;
	new->next = NULL;
	if (!head)
		head = new;
	else
	{
		node = head;
		while (node->next)
			node = node->next;
		node->next = new;
	}
	return (new);
}

void	mem_clear_block(t_mem_block **head)
{
	t_mem_block	*temp;
	t_mem_block	*node;

	if (!(*head))
		return ;
	node = *head;
	while (node)
	{
		temp = node->next;
		if (node->data)
		{
			__real_free(node->data);
			node->data = NULL;
		}
		__real_free(node);
		node = temp;
	}
	*head = NULL;
}

void	*mem_error(void)
{
	const char	*err = "libmem: Out of memory\n";
	int			i;

	i = -1;
	while (err[++i])
		write(STDERR_FILENO, &err[i], 1);
	mem_clear_block(mem_add_new_block(NULL, 0)->head);
	__real_exit(EXIT_FAILURE);
	return (NULL);
}

size_t	mem_find_size(void *data)
{
	t_mem_block	*node;
	size_t		res;

	node = *(mem_add_new_block(NULL, 0)->head);
	while (1)
	{
		if (node->data == data)
			res = node->size;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (res);
}
