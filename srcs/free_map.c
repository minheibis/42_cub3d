#include "cub3d.h"

int		free_map(t_s *s)
{
	free_NULL(s->map.map);
	return (s->rv);
}

int		free_map_row(t_s *s, int row, int rv)
{
	int	i;

	i = 0;
	while (i < row + 1)
	{
		free_NULL(s->map.map[i]);
		i++;
	}
	return (rv);
}

int		free_map_all(t_s *s, int rv)
{
	free_map_row(s, (s->map.map_hei + 1), rv);
	free_map(s);
	return (rv);
}

int		free_tex_map(t_s *s, int rv)
{
	free_tex(s, rv);
	free_map_all(s, rv);
	return (rv);
}
