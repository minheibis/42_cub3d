# include "cub3d.h"

void	free_NULL(void *p)
{
	free(p);
	p = NULL;
}

int		free_return(void *p, int rv)
{
	free_NULL(p);
	return (rv);
}
