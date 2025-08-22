#ifndef MEM_UTILS_H
# define MEM_UTILS_H

# include "mem_structs.h"

extern void	*__real_malloc(size_t size);
extern void	__real_free(void *ptr);
extern void	__real_exit(int status);
extern int	__real_main(int argc, char **argv, char **envp);

t_mem_block	*mem_add_new_block(void *data, size_t size);
void		mem_clear_block(t_mem_block **head);
size_t		mem_find_size(void *data);
void		*mem_error(void);

#endif // MEM_UTILS_H
