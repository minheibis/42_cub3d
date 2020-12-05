/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:09:28 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 15:45:40 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_draw_map(t_s *s)
{
	if ((ft_all_init(s)))
		return (s->rv);
	if (s->flag == 2)
	{
		mlx_hook(s->g.win, X_EVENT_KEY_PRESS, (1L<<0), &ft_deal_key, s);
		mlx_loop_hook(s->g.mlx, &ft_main_loop, s);
		mlx_loop(s->g.mlx);
	}
	else
	{
		ft_main_loop(s);
		if ((s->rv = ft_write_bmp("cub3d.bmp", s)))
			return (free_for_bmp(s, s->rv));
		free_for_bmp(s, s->rv);
	}
	return (0);
}

int		ft_all_init(t_s *s)
{
	if ((s->rv = ft_window_init(s)))
		return (s->rv);
	if ((s->rv = ft_img_init(s)))
		return (free_wind(s, s->rv));
	ft_player_init(s);
	if ((s->rv = ft_wall_sp_init(s)))
		return (free_img(s, s->rv));
	ft_col_init(s);
	ft_sp_init(s);
	if ((s->rv = ft_parse_sp(s)))
		return (free_xpm_img(s, s->rv));
	return (0);
}
