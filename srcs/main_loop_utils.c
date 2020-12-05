/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:10:09 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 12:10:10 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_reset_img(t_s *s)
{
	t_xy	c;

	c.x = 0;
	while (c.x < s->g.img.scre_width)
	{
		c.y = 0;
		while (c.y < s->g.img.scre_height)
		{
			s->g.img.data[to_coord(c.x, c.y, s)] = 0x000000;
			c.y++;
		}
		c.x++;
	}
	return (0);
}
