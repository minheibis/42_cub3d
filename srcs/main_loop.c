/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:10:12 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 12:21:16 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_main_loop(t_s *s)
{
	if ((s->rv = ft_ray_wall(s)))
		return (s->rv);
	if ((s->rv = ft_ray_sp(s)))
		return (s->rv);
	/*
	**put image to window
	*/
	if (s->flag == 2)
	{
		mlx_put_image_to_window(s->g.mlx, s->g.win, s->g.img.ptr, 0, 0);
		/*
		**reset window
		*/
		ft_reset_img(s);
	}
	return (0);
}

int		ft_ray_wall(t_s *s)
{
	int		x;

	x = 0;
	while (x < s->g.img.scre_width)
	{
		ft_ray_wall_x(s, x);
		x++;
	}
	return (0);
}
