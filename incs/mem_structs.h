#ifndef MEM_STRUCTS_H
# define MEM_STRUCTS_H

# include <stddef.h>

typedef struct s_mem_block
{
	void				*data;
	size_t				size;
	struct s_mem_block	**head;
	struct s_mem_block	*next;

}	t_mem_block;

#endif // MEM_STRUCTS_H
