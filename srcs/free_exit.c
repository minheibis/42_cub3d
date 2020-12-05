/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:09:40 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 12:09:41 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		free_xpm_img(t_s *s, int rv)
{
	free_xpm_SP(s, rv);
	free_img(s, rv);
	return (rv);
}

int		free_for_bmp(t_s *s, int rv)
{
	free_tex_map_sp(s, rv);
	free_xpm_SP(s, rv);
	mlx_destroy_image(s->g.mlx, s->g.img.ptr);
	s->g.img.ptr = NULL;
	free_NULL(s->g.mlx);
	return (rv);
}

int		free_exit(t_s *s, int rv)
{
	free_tex_map_sp(s, rv);
	free_xpm_img(s, rv);
	return (rv);
}
