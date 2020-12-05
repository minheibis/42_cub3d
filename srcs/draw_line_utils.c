/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:09:25 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 15:45:32 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		to_coord(int x, int y, t_s *s)
{
	int	len;

	len = y * s->g.img.scre_width + x;
	return (len);
}

int		ft_decide_wall(t_s *s)
{
	if (s->g.h_c.side == 0)
	{
		if (s->g.r.raydiry < 0)
			s->g.ws.now = s->g.ws.n;
		else
			s->g.ws.now = s->g.ws.s;
	}
	else
	{
		if (s->g.r.raydirx > 0)
			s->g.ws.now = s->g.ws.e;
		else
			s->g.ws.now = s->g.ws.w;
	}
	return (0);
}

int			ft_draw_line_calc(t_s *s)
{
	if (s->g.h_c.side == 0)
		s->g.d_c.wallx = s->g.p.posx + s->g.h_c.prepwalldist * s->g.r.raydirx;
	else
		s->g.d_c.wallx = s->g.p.posy + s->g.h_c.prepwalldist * s->g.r.raydiry;
	s->g.d_c.wallx -= floor(s->g.d_c.wallx);
	if ((s->g.h_c.side == 0 && s->g.r.raydiry < 0) || (s->g.h_c.side == 1 && s->g.r.raydirx > 0))
		s->g.d_c.texx = floor(s->g.d_c.wallx * s->g.ws.now.width);
	else
		s->g.d_c.texx = floor((1 - s->g.d_c.wallx) * s->g.ws.now.width);
	s->g.d_c.step = (double)s->g.ws.now.height / s->g.d_c.lineh;
	if (s->g.d_c.lineh > s->g.img.scre_height)
		s->g.d_c.texpos = s->g.ws.now.height * ((1 - (double)s->g.img.scre_height / (double)s->g.d_c.lineh) / 2);
	else
		s->g.d_c.texpos = 0;
	return (0);
}

int		ft_draw_line_draw(t_s *s, int x)
{
	int	y;

	y = 0;
	while (y < s->g.d_c.draws)
	{
		s->g.img.data[to_coord(x, y, s)] = s->map.cel_col_int;
		y++;
	}
	while (y < s->g.d_c.drawe)
	{
		s->g.d_c.texy = floor(s->g.d_c.texpos);
		s->g.d_c.color = s->g.ws.now.data[s->g.ws.now.width * s->g.d_c.texy + s->g.d_c.texx];
		s->g.img.data[to_coord(x, y, s)] = s->g.d_c.color;
		s->g.d_c.texpos += s->g.d_c.step;
		y++;
	}
	while (y < s->g.img.scre_height)
	{
		s->g.img.data[to_coord(x, y, s)] = s->map.flo_col_int;
		y++;
	}
	return (0);
}
