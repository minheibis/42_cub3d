#include "cub3d.h"

int		ft_dir_init(t_s *s)
{
	if (s->map.player_dir == 'N')
	{
		s->g.p.dirX = 0.0;
		s->g.p.dirY = -1.0;
		s->g.p.planeX = -0.66;
		s->g.p.planeY = 0.0;
	}
	else if (s->map.player_dir == 'S')
	{
		s->g.p.dirX = 0.0;
		s->g.p.dirY = 1.0;
		s->g.p.planeX = 0.66;
		s->g.p.planeY = 0.0;
	}
	else
		return (ft_dir_init_EW(s));
	return (0);
}

int		ft_dir_init_EW(t_s *s)
{
	if (s->map.player_dir == 'E')
	{
		s->g.p.dirX = 1.0;
		s->g.p.dirY = 0.0;
		s->g.p.planeX = 0.0;
		s->g.p.planeY = -0.66;
	}
	else if (s->map.player_dir == 'W')
	{
		s->g.p.dirX = -1.0;
		s->g.p.dirY = 0.0;
		s->g.p.planeX = 0.0;
		s->g.p.planeY = 0.66;
	}
	return (0);
}
