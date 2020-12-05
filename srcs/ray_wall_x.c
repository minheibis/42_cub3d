/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_wall_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:10:33 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 14:18:36 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_ray_wall_x(t_s *s, int x)
{
	ft_calc_pos(s, x);
	ft_calc_hit(s);
	ft_calc_line(s);
	ft_draw_line(s, x);
	/*
	**save zbuff for sprite
	*/
	s->g.sp_i.zbuff[x] = s->g.h_c.prepwalldist;
	return (0);
}

int		ft_calc_pos(t_s *s, int x)
{
	/*
	**calculate ray position and direction
	**	camerax: x-coordinate in camera space,
	**	 the right side of the screen is 1, center is 0, left side is -1
	*/
	s->g.r.camerax = 1 - (x * 2 / (double)s->g.img.scre_width);
	s->g.r.raydirx = s->g.p.dirx + s->g.p.planex * s->g.r.camerax;
	s->g.r.raydiry = s->g.p.diry + s->g.p.planey * s->g.r.camerax;
	/*
	**which box of the map we are in
	*/
	s->g.h_c.mapx = floor(s->g.p.posx);
	s->g.h_c.mapy = floor(s->g.p.posy);
	/*
	**length of ray from one x-side to next x-side or one y-side to next y-side
	** different from oldmain.c
	*/
	if (s->g.r.raydirx == 0)
		s->g.h_c.deltadistx = s->g.img.scre_width;
	else
		s->g.h_c.deltadistx = sqrt(1 + (pow(s->g.r.raydiry, 2) / pow(s->g.r.raydirx, 2)));
	if (s->g.r.raydiry == 0)
		s->g.h_c.deltadisty = s->g.img.scre_height;
	else
		s->g.h_c.deltadisty = sqrt(1 + (pow(s->g.r.raydirx, 2) / pow(s->g.r.raydiry, 2)));
	return (0);
}

int		ft_calc_hit(t_s *s)
{
	ft_calc_hit_init(s);
	ft_calc_hit_dda(s);
	return (0);
}

int		ft_calc_line(t_s *s)
{
	/*
	**Calculate distance projected on camera direction
	** (Euclidean distance will give fisheye effect)
	** x and y are opposite from the old main
	*/
	if (s->g.h_c.side == 0)
		s->g.h_c.prepwalldist = (s->g.h_c.mapy + (1 - s->g.h_c.stepy) / 2 - s->g.p.posy) / s->g.r.raydiry;
	else
		s->g.h_c.prepwalldist = (s->g.h_c.mapx + (1 - s->g.h_c.stepx) / 2 - s->g.p.posx) / s->g.r.raydirx;
	/*
	**in case of over flow
	*/
	if (s->g.h_c.prepwalldist < 0.01)
		s->g.h_c.prepwalldist = 0.01;
	/*
	** calculate height of line to draw on screen
	*/
	s->g.d_c.lineh = floor(s->g.img.scre_height / s->g.h_c.prepwalldist);
	/*
	**caluculate lowest and heighest pixel to fill in current stripe
	*/
	s->g.d_c.draws = s->g.img.scre_height / 2 - s->g.d_c.lineh / 2;
	if (s->g.d_c.draws < 0)
		s->g.d_c.draws = 0;
	s->g.d_c.drawe = s->g.img.scre_height / 2 + s->g.d_c.lineh / 2;
	if (s->g.d_c.drawe >= s->g.img.scre_height)
		s->g.d_c.drawe = s->g.img.scre_height - 1;
	return (0);
}

int		ft_draw_line(t_s *s, int x)
{
	ft_decide_wall(s);
	ft_draw_line_calc(s);
	ft_draw_line_draw(s, x);
	return (0);
}
