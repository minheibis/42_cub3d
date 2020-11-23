#include "cub3d.h"

int		ft_parse_sp(t_s *s)
{
	/*
	**set zbuffer
	*/
	if (!(s->g.sp_i.ZBuff = (double *)malloc((s->g.img.scre_width) * sizeof(double))))
		return (MALLOC_ERROR_ZBUFF);
	/*
	**set the int* etc for sprites
	*/
	if (!(s->g.sp_i.sp_x = (int *)malloc((s->map.sp_count) * sizeof(int))))
		return (MALLOC_ERROR_SP_X);
	if (!(s->g.sp_i.sp_y = (int *)malloc((s->map.sp_count) * sizeof(int))))
		return (MALLOC_ERROR_SP_Y);
	if (!(s->g.sp_i.spOrd = (int *)malloc((s->map.sp_count) * sizeof(int))))
		return (MALLOC_ERROR_SPORD);
	if (!(s->g.sp_i.spDist = (double *)malloc((s->map.sp_count) * sizeof(double))))
		return (MALLOC_ERROR_SPDIST);
	ft_search_sp(s);
	return (0);
}

int		ft_search_sp(t_s *s)
{
	t_xy	c;
	int		i;

	//printf
	printf("ft_search_sp: s->map.map_hei: [%d]\n", s->map.map_hei);
	printf("ft_search_sp: s->map.map_wid: [%d]\n", s->map.map_wid);
	i = 0;
	c.y = 1;
	while (c.y < s->map.map_hei + 2)
	{
		c.x = 1;
		while (c.x < s->map.map_wid + 2)
		{
			if (s->map.map[c.y][c.x] == 'y')
			{
				s->g.sp_i.sp_x[i] = c.x;
				s->g.sp_i.sp_y[i] = c.y;
				printf("ft_search_sp: s->g.sp_i.sp_x[i]: [%d]\n", s->g.sp_i.sp_x[i]);
				printf("ft_search_sp: s->g.sp_i.sp_y[i]: [%d]\n", s->g.sp_i.sp_y[i]);
				i++;
			}
			c.x++;
		}
		c.y++;
	}
	return (0);
}
