#include "cub3d.h"

int		ft_sort_sp_calc(t_s *s)
{
	int	i;

	i = 0;
	while (i < s->map.sp_count)
	{
		s->g.sp_i.spOrd[i] = i;
		s->g.sp_i.spDist[i] = pow((s->g.p.posX - s->g.sp_i.sp_x[i]), 2) + pow((s->g.p.posY - s->g.sp_i.sp_y[i]), 2);
		i++;
	}
	return (0);
}

int		ft_sort_sp_sort(t_s *s)
{
	t_ij	c;
	int		tmp_int;
	double	tmp_double;

	c.i = 0;
	while (c.i < s->map.sp_count)
	{
		c.j = c.i + 1;
		while (c.j < s->map.sp_count)
		{
			if (s->g.sp_i.spDist[c.i] < s->g.sp_i.spDist[c.j])
			{
				tmp_int = s->g.sp_i.spOrd[c.i];
				tmp_double = s->g.sp_i.spDist[c.i];
				s->g.sp_i.spOrd[c.i] = s->g.sp_i.spOrd[c.j];
				s->g.sp_i.spDist[c.i] = s->g.sp_i.spDist[c.j];
				s->g.sp_i.spOrd[c.j] = tmp_int;
				s->g.sp_i.spDist[c.j] = tmp_double;
			}
			c.j++;
		}
		c.i++;
	}
	return (0);
}
