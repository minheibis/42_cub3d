#include "cub3d.h"

void	ft_show_map(t_s *s)
{
	int i;
	i = 0;
	while (i < s->map.map_hei + 2)
	{
		printf("s->map.map[i]: [%2d][%s]\n", i, s->map.map[i]);
		i++;
	}
}
