/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_hit_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:08:58 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 12:12:58 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			s->g.h_c.side = 1; //is this true?a should be 0? changed to 0
		}
		else
		{
			s->g.h_c.sideDistY += s->g.h_c.deltaDistY;
			s->g.h_c.mapY += s->g.h_c.stepY;
			s->g.h_c.side = 0;
		}
		/*
		**Check if ray has hit a wall
		*/
		if (s->map.map[s->g.h_c.mapY][s->g.h_c.mapX] == '1')
		{
			s->g.h_c.hit = 1;
		}
	}
	return (0);
}
