/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sp_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:09:30 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 14:18:36 by hyuki            ###   ########.fr       */
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
	/*
	**translate sprite position to relative to camera
	*/
	s->g.sp_i.spx = s->g.sp_i.sp_x[s->g.sp_i.spord[i]] - s->g.p.posx;
	s->g.sp_i.spy = s->g.sp_i.sp_y[s->g.sp_i.spord[i]] - s->g.p.posy;
	/*
	**transform sprite with inverse camera matrix
	*/
	s->g.sp_i.invdet = 1.0 / (s->g.p.planex * s->g.p.diry - s->g.p.dirx * s->g.p.planey);
	s->g.sp_i.trx = s->g.sp_i.invdet * (s->g.p.diry * s->g.sp_i.spx - s->g.p.dirx * s->g.sp_i.spy);
	s->g.sp_i.try = s->g.sp_i.invdet * (-s->g.p.planey * s->g.sp_i.spx + s->g.p.planex * s->g.sp_i.spy);
	/*
	**this is actually the depth inside the screen, that what Z is in 3D
	** is this true?
	*/
	s->g.sp_i.spscx = (int)floor(s->g.img.scre_width * (0.5 - s->g.sp_i.trx / (s->g.sp_i.try * 0.66 * 2)));
 	return (0);
}

int		ft_draw_sp_one_hw(t_s *s)
{
	/*
	**calculate height of the sprite on screen
	** same as using prepwalldist
	*/
	s->g.sp_i.sph = abs((int)floor(s->g.img.scre_height / s->g.sp_i.try));
	s->g.sp_i.drawsy = -s->g.sp_i.sph / 2 + s->g.img.scre_height / 2;
	if (s->g.sp_i.drawsy < 0)
		s->g.sp_i.drawsy = 0;
	s->g.sp_i.drawey = s->g.sp_i.sph / 2 + s->g.img.scre_height / 2;
	if (s->g.sp_i.drawey >= s->g.img.scre_height)
		s->g.sp_i.drawey = s->g.img.scre_height - 1;
	/*
	**calculate width of the sprite on screen
	** same as the sph for drawing a square sprite
	*/
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
	/*
	**loop through every vertical stripe of the sprite on screen
	*/
	s->g.sp_i.stripe = s->g.sp_i.drawsx;
	while (s->g.sp_i.stripe < s->g.sp_i.drawex)
	{
		s->g.d_c.texx = (int)floor(((double)s->g.sp_i.stripe - ((double)s->g.sp_i.spscx -(double)s->g.sp_i.spw / 2)) * (double)s->g.ws.sp.width / (double)s->g.sp_i.spw);
		/*
		**the conditions in the if are
		**1) it is in front of camera plane so you don't see things behind you: s->g.sp_i.try > 0
		**2) it is on the screen (left side): s->g.sp_i.stripe > 0
		**3) it is on the screen (right side): s->g.sp_i.stripe < s->g.img.scre_width
		**4) it is in front of the wall: s->g.sp_i.try < s->g.sp_i.zbuff[s->g.sp_i.stripe]
		**/
		if (s->g.sp_i.try > 0 && s->g.sp_i.stripe > 0 && s->g.sp_i.stripe < s->g.img.scre_width && s->g.sp_i.try < s->g.sp_i.zbuff[s->g.sp_i.stripe])
		{
			/*
			**for every pixel for the current stripe
			*/
			y = s->g.sp_i.drawsy;
			while (y < s->g.sp_i.drawey)
			{
				s->g.d_c.texy = (int)floor(((double)y - ((double)s->g.img.scre_height / 2 - (double)s->g.sp_i.sph / 2)) * (double)s->g.ws.sp.height) / (double)s->g.sp_i.sph;
				s->g.d_c.color = s->g.ws.sp.data[s->g.ws.sp.width * s->g.d_c.texy + s->g.d_c.texx];
				if (s->g.d_c.color != 0x000000)
					s->g.img.data[to_coord(s->g.sp_i.stripe, y, s)] = s->g.d_c.color;
				y++;
			}
		}
		s->g.sp_i.stripe++;
	}
	return (0);
}
