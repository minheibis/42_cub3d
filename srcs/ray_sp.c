#include "cub3d.h"

int		ft_ray_sp(t_s *s)
{
	ft_sort_sp(s);
	//printf
	// int i;
	// i = 0;
	// while (i < s->map.sp_count)
	// {
	// 	printf("ft_ray_sp: s->g.sp_i.spOrd[i]: [%d][%d]\n", i, s->g.sp_i.spOrd[i]);
	// 	printf("ft_ray_sp: s->g.sp_i.spDist[i]: [%d][%lf]\n", i, s->g.sp_i.spDist[i]);
	// 	i++;
	// }
	ft_draw_sp(s);
	return (0);
}

int		ft_sort_sp(t_s *s)
{
	ft_sort_sp_calc(s);
	ft_sort_sp_sort(s);
	return (0);
}

int		ft_draw_sp(t_s *s)
{
	int	i;

	i = 0;
	while (i < s->map.sp_count)
	{
		ft_draw_sp_one(s, i);
		i++;
	}
	return (0);
}
