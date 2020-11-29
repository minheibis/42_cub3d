#include "cub3d.h"

int		ft_parse_sp(t_s *s)
{
	/*
	**set zbuffer
	*/
	if (!(s->g.sp_i.ZBuff = (double *)malloc((s->g.img.scre_width + 1) * sizeof(double))))
		return (MALLOC_ERROR_ZBUFF);
	s->g.sp_i.ZBuff[s->g.img.scre_width] = 0;
	/*
	**set the int* etc for sprites
	*/
	if (!(s->g.sp_i.sp_x = (double *)malloc((s->map.sp_count) * sizeof(double))))
		return (free_sp_Zbuff(s, MALLOC_ERROR_SP_X));
	if (!(s->g.sp_i.sp_y = (double *)malloc((s->map.sp_count) * sizeof(double))))
		return (free_sp_x(s, MALLOC_ERROR_SP_Y));
	if (!(s->g.sp_i.spOrd = (int *)malloc((s->map.sp_count) * sizeof(int))))
		return (free_sp_y(s, MALLOC_ERROR_SPORD));
	if (!(s->g.sp_i.spDist = (double *)malloc((s->map.sp_count) * sizeof(double))))
		return (free_spOrd(s, MALLOC_ERROR_SPDIST));
	ft_search_sp(s);
	return (0);
}

int		ft_search_sp(t_s *s)
{
	t_xy	c;
	int		i;

	//printf
	// printf("ft_search_sp: s->map.map_hei: [%d]\n", s->map.map_hei);
	// printf("ft_search_sp: s->map.map_wid: [%d]\n", s->map.map_wid);
	i = 0;
	c.y = 1;
	while (c.y < s->map.map_hei + 2)
	{
		c.x = 1;
		while (c.x < s->map.map_wid + 2)
		{
			if (s->map.map[c.y][c.x] == 'y')
			{
				s->g.sp_i.sp_x[i] = c.x + 0.5;
				s->g.sp_i.sp_y[i] = c.y + 0.5;
				// printf("ft_search_sp: s->g.sp_i.sp_x[i]: [%lf]\n", s->g.sp_i.sp_x[i]);
				// printf("ft_search_sp: s->g.sp_i.sp_y[i]: [%lf]\n", s->g.sp_i.sp_y[i]);
				i++;
			}
			c.x++;
		}
		c.y++;
	}
	return (0);
}
