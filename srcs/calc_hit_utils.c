/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_hit_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:08:58 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 13:52:10 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_calc_hit_init(t_s *s)
{
	s->g.h_c.hit = 0;
	if (s->g.r.raydirx < 0)
	{
		s->g.h_c.stepx = -1;
		s->g.h_c.sidedistx = (s->g.p.posx - s->g.h_c.mapx) * s->g.h_c.deltadistx;
	}
	else
	{
		s->g.h_c.stepx = 1;
		s->g.h_c.sidedistx = (s->g.h_c.mapx + 1 - s->g.p.posx) * s->g.h_c.deltadistx;
	}
	if (s->g.r.raydiry < 0)
	{
		s->g.h_c.stepy = -1;
		s->g.h_c.sidedisty = (s->g.p.posy - s->g.h_c.mapy) * s->g.h_c.deltadisty;
	}
	else
	{
		s->g.h_c.stepy = 1;
		s->g.h_c.sidedisty = (s->g.h_c.mapy + 1 - s->g.p.posy) * s->g.h_c.deltadisty;
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
		if (s->g.h_c.sidedisty > s->g.h_c.sidedistx)
		{
			s->g.h_c.sidedistx += s->g.h_c.deltadistx;
			s->g.h_c.mapx += s->g.h_c.stepx;
			s->g.h_c.side = 1; //is this true?a should be 0? changed to 0
		}
		else
		{
			s->g.h_c.sidedisty += s->g.h_c.deltadisty;
			s->g.h_c.mapy += s->g.h_c.stepy;
			s->g.h_c.side = 0;
		}
		/*
		**Check if ray has hit a wall
		*/
		if (s->map.map[s->g.h_c.mapy][s->g.h_c.mapx] == '1')
		{
			s->g.h_c.hit = 1;
		}
	}
	return (0);
}
