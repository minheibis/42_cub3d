#include "cub3d.h"

int		ft_calc_hit_init(t_s *s)
{
	s->g.h_c.hit = 0;
	if (s->g.r.rayDirX < 0)
	{
		s->g.h_c.stepX = -1;
		s->g.h_c.sideDistX = (s->g.p.posX - s->g.h_c.mapX) * s->g.h_c.deltaDistX;
	}
	else
	{
		s->g.h_c.stepX = 1;
		s->g.h_c.sideDistX = (s->g.h_c.mapX + 1 - s->g.p.posX) * s->g.h_c.deltaDistX;
	}
	if (s->g.r.rayDirY < 0)
	{
		s->g.h_c.stepY = -1;
		s->g.h_c.sideDistY = (s->g.p.posY - s->g.h_c.mapY) * s->g.h_c.deltaDistY;
	}
	else
	{
		s->g.h_c.stepY = 1;
		s->g.h_c.sideDistY = (s->g.h_c.mapY + 1 - s->g.p.posY) * s->g.h_c.deltaDistY;
	}
	return (0);
}

int		ft_calc_hit_DDA(t_s *s)
{
	while (s->g.h_c.hit == 0)
	{
		/*
		**jump to next map square, OR in x-dircection, OR in y-direction
		*/
		if (s->g.h_c.sideDistY > s->g.h_c.sideDistX)
		{
			s->g.h_c.sideDistX += s->g.h_c.deltaDistX;
			s->g.h_c.mapX += s->g.h_c.stepX;
			s->g.h_c.side = 1; //is this true? should be 0? changed to 0
		}
		else
		{
			s->g.h_c.sideDistY += s->g.h_c.deltaDistY;
			s->g.h_c.mapY += s->g.h_c.stepY;
			s->g.h_c.side = 0; //is this true? should be 1?
		}
		/*
		**Check if ray has hit a wall
		*/
		if (s->map.map[s->g.h_c.mapY][s->g.h_c.mapX] == '1')
		{
			s->g.h_c.hit = 1;
			//printf
			// printf("ft_calc_hit_DDA: 55: s->g.h_c.mapX: [%d]\n", s->g.h_c.mapX);
			// printf("ft_calc_hit_DDA: 56: s->g.h_c.mapY: [%d]\n", s->g.h_c.mapY);
			// printf("ft_calc_hit_DDA: 56: s->g.h_c.side: [%d]\n", s->g.h_c.side);
		}
	}
	return (0);
}
