/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:09:44 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 14:13:43 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		free_mlx(t_s *s, int rv)
{
	free_null(s->g.mlx);
	return (rv);
}

int		free_wind(t_s *s, int rv)
{
	if (s->flag == 2)
		mlx_destroy_window(s->g.mlx, s->g.win);
	s->g.win = NULL;
	free_mlx(s, rv);
	return (rv);
}

int		free_img(t_s *s, int rv)
{
	mlx_destroy_image(s->g.mlx, s->g.img.ptr);
	free_wind(s, rv);
	s->g.img.ptr = NULL;
	return (rv);
}
