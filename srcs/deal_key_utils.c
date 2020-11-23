#include "cub3d.h"

int		ft_map_in(char c)
{
	if (c == 'w' || c == 'y' || ft_is_NSEW(c))
		return (1);
	else
		return (0);
}
