/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:10:27 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 14:11:00 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_parse_sp(t_s *s)
{
	/*
	**set zbuffer
	*/
	if (!(s->g.sp_i.zbuff = (double *)malloc((s->g.img.scre_width + 1) * sizeof(double))))
		return (MALLOC_ERROR_ZBUFF);
	s->g.sp_i.zbuff[s->g.img.scre_width] = 0;
	/*
	**set the int* etc for sprites
	*/
	if (!(s->g.sp_i.sp_x = (double *)malloc((s->map.sp_count) * sizeof(double))))
		return (free_sp_zbuff(s, MALLOC_ERROR_SP_X));
	if (!(s->g.sp_i.sp_y = (double *)malloc((s->map.sp_count) * sizeof(double))))
		return (free_sp_x(s, MALLOC_ERROR_SP_Y));
	if (!(s->g.sp_i.spord = (int *)malloc((s->map.sp_count) * sizeof(int))))
		return (free_sp_y(s, MALLOC_ERROR_SPORD));
	if (!(s->g.sp_i.spdist = (double *)malloc((s->map.sp_count) * sizeof(double))))
		return (free_spord(s, MALLOC_ERROR_SPDIST));
	ft_search_sp(s);
	return (0);
}

int		ft_search_sp(t_s *s)
{
	t_xy	c;
	int		i;

	i = 0;
	c.y = 1;
	while (c.y < s->map.map_hei + 2)
	{
		c.x = 1;
		while (c.x < s->map.map_wid + 2)
		{
			if (s->map.map[c.y][c.x] == 'y')
			{
				s->g.sp_i.sp_x[i] = c.x + 0.5;
				s->g.sp_i.sp_y[i] = c.y + 0.5;
				i++;
			}
			c.x++;
		}
		c.y++;
	}
	return (0);
}
