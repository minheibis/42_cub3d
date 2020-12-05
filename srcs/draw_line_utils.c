/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:09:25 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 12:15:43 by hyuki            ###   ########.fr       */
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
		if (s->g.r.rayDirY < 0)
			s->g.ws.now = s->g.ws.N;
		else
			s->g.ws.now = s->g.ws.S;
	}
	else
	{
		if (s->g.r.rayDirX > 0)
			s->g.ws.now = s->g.ws.E;
		else
			s->g.ws.now = s->g.ws.W;
	}
	return (0);
}

int			ft_draw_line_calc(t_s *s)
{
	/*
	**calculate value of wallX
	*/
	if (s->g.h_c.side == 0)
		s->g.d_c.wallX = s->g.p.posX + s->g.h_c.prepWallDist * s->g.r.rayDirX;
	else
		s->g.d_c.wallX = s->g.p.posY + s->g.h_c.prepWallDist * s->g.r.rayDirY;
	s->g.d_c.wallX -= floor(s->g.d_c.wallX);
	/*
	**x coordinate on the texture
	**	depend on the way tex file is read
	*/
	if ((s->g.h_c.side == 0 && s->g.r.rayDirY < 0) || (s->g.h_c.side == 1 && s->g.r.rayDirX > 0))
		s->g.d_c.texX = floor(s->g.d_c.wallX * s->g.ws.now.width);
	else
		s->g.d_c.texX = floor((1 - s->g.d_c.wallX) * s->g.ws.now.width);
	/*
	**how much to increase the texture coordinate per screen pixel
	*/
	s->g.d_c.step = (double)s->g.ws.now.height / s->g.d_c.lineH;
	/*
	**starting texture coordinate
	** different from old main
	*/
	if (s->g.d_c.lineH > s->g.img.scre_height)
		s->g.d_c.texPos = s->g.ws.now.height * ((1 - (double)s->g.img.scre_height / (double)s->g.d_c.lineH) / 2);
	else
		s->g.d_c.texPos = 0;
	return (0);
}

int		ft_draw_line_draw(t_s *s, int x)
{
	int	y;

	y = 0;
	while (y < s->g.d_c.drawS)
	{
		s->g.img.data[to_coord(x, y, s)] = s->map.cel_col_int;
		y++;
	}
	while (y < s->g.d_c.drawE)
	{
		/*
		**cast the texture coordinate to integer, ans mask with (texHeight - 1) in case of overflow
		** different from old main
		*/
		s->g.d_c.texY = floor(s->g.d_c.texPos);
		s->g.d_c.color = s->g.ws.now.data[s->g.ws.now.width * s->g.d_c.texY + s->g.d_c.texX];
		s->g.img.data[to_coord(x, y, s)] = s->g.d_c.color;
		s->g.d_c.texPos += s->g.d_c.step;
		y++;
	}
	while (y < s->g.img.scre_height)
	{
		s->g.img.data[to_coord(x, y, s)] = s->map.flo_col_int;
		y++;
	}
	return (0);
}
