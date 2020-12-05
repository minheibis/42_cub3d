/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_hit_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:08:58 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 15:39:54 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_calc_hit_init(t_s *s)
{
	s->g.h_c.hit = 0;
	if (s->g.r.raydirx < 0)
	{
		s->g.h_c.stepx = -1;
		s->g.h_c.sidedistx =
		(s->g.p.posx - s->g.h_c.mapx) * s->g.h_c.deltadistx;
	}
	else
	{
		s->g.h_c.stepx = 1;
		s->g.h_c.sidedistx =
		(s->g.h_c.mapx + 1 - s->g.p.posx) * s->g.h_c.deltadistx;
	}
	return (ft_calc_hit_init_2(s));
}

int		ft_calc_hit_init_2(t_s *s)
{
	if (s->g.r.raydiry < 0)
	{
		s->g.h_c.stepy = -1;
		s->g.h_c.sidedisty =
		(s->g.p.posy - s->g.h_c.mapy) * s->g.h_c.deltadisty;
	}
	else
	{
		s->g.h_c.stepy = 1;
		s->g.h_c.sidedisty =
		(s->g.h_c.mapy + 1 - s->g.p.posy) * s->g.h_c.deltadisty;
	}
	return (0);
}

int		ft_calc_hit_dda(t_s *s)
{
	while (s->g.h_c.hit == 0)
	{
		if (s->g.h_c.sidedisty > s->g.h_c.sidedistx)
		{
			s->g.h_c.sidedistx += s->g.h_c.deltadistx;
			s->g.h_c.mapx += s->g.h_c.stepx;
			s->g.h_c.side = 1;
		}
		else
		{
			s->g.h_c.sidedisty += s->g.h_c.deltadisty;
			s->g.h_c.mapy += s->g.h_c.stepy;
			s->g.h_c.side = 0;
		}
		if (s->map.map[s->g.h_c.mapy][s->g.h_c.mapx] == '1')
		{
			s->g.h_c.hit = 1;
		}
	}
	return (0);
}
