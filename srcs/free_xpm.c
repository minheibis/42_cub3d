/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:09:52 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 12:09:53 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		free_xpm_N(t_s *s, int rv)
{
	mlx_destroy_image(s->g.mlx, s->g.ws.N.ptr);
	return (rv);
}

int		free_xpm_S(t_s *s, int rv)
{
	free_xpm_N(s, rv);
	mlx_destroy_image(s->g.mlx, s->g.ws.S.ptr);
	return (rv);
}

int		free_xpm_W(t_s *s, int rv)
{
	free_xpm_S(s, rv);
	mlx_destroy_image(s->g.mlx, s->g.ws.W.ptr);
	return (rv);
}

int		free_xpm_E(t_s *s, int rv)
{
	free_xpm_W(s, rv);
	mlx_destroy_image(s->g.mlx, s->g.ws.E.ptr);
	return (rv);
}

int		free_xpm_SP(t_s *s, int rv)
{
	free_xpm_E(s, rv);
	mlx_destroy_image(s->g.mlx, s->g.ws.sp.ptr);
	return (rv);
}
