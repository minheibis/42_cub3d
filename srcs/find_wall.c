/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:09:35 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/06 12:53:47 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_find_wall_row_for(t_s *s)
{
	t_ijc	var;

	var.i = s->map.player[0];
	var.j = s->map.player[1];
	while (var.j <= s->map.map_wid + 1)
	{
		var.c = ft_check_p_row(s, var.i, var.j);
		if (var.c == IS_WALL)
			return (0);
		else if (var.c == NO_WALL)
			return (1);
		else
			var.j++;
	}
	return (0);
}

int		ft_find_wall_row_bac(t_s *s)
{
	t_ijc	var;

	var.i = s->map.player[0];
	var.j = s->map.player[1] - 1;
	while (var.j >= 0)
	{
		var.c = ft_check_p_row(s, var.i, var.j);
		if (var.c == IS_WALL)
			return (0);
		else if (var.c == NO_WALL)
			return (1);
		else
			var.j--;
	}
	return (0);
}

int		ft_find_wall_col_for(t_s *s)
{
	t_ijc	var;

	var.i = s->map.player[0];
	var.j = s->map.player[1];
	while (var.i <= s->map.map_hei + 1)
	{
		var.c = ft_check_p_col(s, var.i, var.j);
		if (var.c == IS_WALL)
			return (0);
		else if (var.c == NO_WALL)
			return (1);
		else
			var.i++;
	}
	return (0);
}

int		ft_find_wall_col_bac(t_s *s)
{
	t_ijc	var;

	var.i = s->map.player[0] - 1;
	var.j = s->map.player[1];
	while (var.i >= 0)
	{
		var.c = ft_check_p_col(s, var.i, var.j);
		if (var.c == IS_WALL)
			return (0);
		else if (var.c == NO_WALL)
			return (1);
		else
			var.i--;
	}
	return (0);
}
