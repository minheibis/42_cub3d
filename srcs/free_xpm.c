/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:09:52 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 15:23:43 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		free_xpm_n(t_s *s, int rv)
{
	mlx_destroy_image(s->g.mlx, s->g.ws.n.ptr);
	return (rv);
}

int		free_xpm_s(t_s *s, int rv)
{
	free_xpm_n(s, rv);
	mlx_destroy_image(s->g.mlx, s->g.ws.s.ptr);
	return (rv);
}

int		free_xpm_w(t_s *s, int rv)
{
	free_xpm_s(s, rv);
	mlx_destroy_image(s->g.mlx, s->g.ws.w.ptr);
	return (rv);
}

int		free_xpm_e(t_s *s, int rv)
{
	free_xpm_w(s, rv);
	mlx_destroy_image(s->g.mlx, s->g.ws.e.ptr);
	return (rv);
}

int		free_xpm_sp(t_s *s, int rv)
{
	free_xpm_e(s, rv);
	mlx_destroy_image(s->g.mlx, s->g.ws.sp.ptr);
	return (rv);
}
