/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sp_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:09:30 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/09 09:55:13 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_draw_sp_one(t_s *s, int i)
{
	ft_draw_sp_one_pos(s, i);
	ft_draw_sp_one_hw(s);
	ft_draw_sp_one_draw(s);
	return (0);
}

int		ft_draw_sp_one_pos(t_s *s, int i)
{
	s->g.sp_i.spx = s->g.sp_i.sp_x[s->g.sp_i.spord[i]] - s->g.p.posx;
	s->g.sp_i.spy = s->g.sp_i.sp_y[s->g.sp_i.spord[i]] - s->g.p.posy;
	s->g.sp_i.invdet = 1.0 /
		(s->g.p.planex * s->g.p.diry - s->g.p.planey * s->g.p.dirx);
	s->g.sp_i.trx = s->g.sp_i.invdet *
		(s->g.p.diry * s->g.sp_i.spx - s->g.p.dirx * s->g.sp_i.spy);
	s->g.sp_i.try = s->g.sp_i.invdet *
		(-s->g.p.planey * s->g.sp_i.spx + s->g.p.planex * s->g.sp_i.spy);
	s->g.sp_i.spscx = (int)floor(s->g.img.scre_width *
		(0.5 + s->g.sp_i.trx / (s->g.sp_i.try * 0.66 * 2)));
	return (0);
}

int		ft_draw_sp_one_hw(t_s *s)
{
	s->g.sp_i.sph = abs((int)floor(s->g.img.scre_height / s->g.sp_i.try));
	s->g.sp_i.drawsy = -s->g.sp_i.sph / 2 + s->g.img.scre_height / 2;
	if (s->g.sp_i.drawsy < 0)
		s->g.sp_i.drawsy = 0;
	s->g.sp_i.drawey = s->g.sp_i.sph / 2 + s->g.img.scre_height / 2;
	if (s->g.sp_i.drawey >= s->g.img.scre_height)
		s->g.sp_i.drawey = s->g.img.scre_height - 1;
	s->g.sp_i.spw = s->g.sp_i.sph;
	s->g.sp_i.drawsx = -s->g.sp_i.spw / 2 + s->g.sp_i.spscx;
	if (s->g.sp_i.drawsx < 0)
		s->g.sp_i.drawsx = 0;
	s->g.sp_i.drawex = s->g.sp_i.spw / 2 + s->g.sp_i.spscx;
	if (s->g.sp_i.drawex >= s->g.img.scre_width)
		s->g.sp_i.drawex = s->g.img.scre_width - 1;
	return (0);
}

int		ft_draw_sp_one_draw(t_s *s)
{
	int	y;

	s->g.sp_i.stripe = s->g.sp_i.drawsx;
	while (s->g.sp_i.stripe < s->g.sp_i.drawex)
	{
		s->g.d_c.texx = (int)floor(((double)s->g.sp_i.stripe -
			((double)s->g.sp_i.spscx - (double)s->g.sp_i.spw / 2)) *
			(double)s->g.ws.sp.width / (double)s->g.sp_i.spw);
		if (s->g.sp_i.try > 0 && s->g.sp_i.stripe > 0 &&
			s->g.sp_i.stripe < s->g.img.scre_width &&
			s->g.sp_i.try < s->g.sp_i.zbuff[s->g.sp_i.stripe])
		{
			y = s->g.sp_i.drawsy;
			while (y < s->g.sp_i.drawey)
			{
				ft_draw_sp_one_draw_y(s, y);
				y++;
			}
		}
		s->g.sp_i.stripe++;
	}
	return (0);
}

int		ft_draw_sp_one_draw_y(t_s *s, int y)
{
	s->g.d_c.texy = (int)floor(((double)y -
		((double)s->g.img.scre_height / 2 - (double)s->g.sp_i.sph / 2)) *
		(double)s->g.ws.sp.height / (double)s->g.sp_i.sph);
	s->g.d_c.color = s->g.ws.sp.data[s->g.ws.sp.width *
		s->g.d_c.texy + s->g.d_c.texx];
	if (s->g.d_c.color != 0x000000)
		s->g.img.data[to_coord(s->g.sp_i.stripe, y, s)] = s->g.d_c.color;
	return (0);
}
