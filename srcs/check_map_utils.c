/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:09:01 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 15:41:16 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_is_nsew(char c)
{
	if (c == 'N')
		return (1);
	else if (c == 'S')
		return (1);
	else if (c == 'E')
		return (1);
	else if (c == 'W')
		return (1);
	else
		return (0);
}

int		ft_find_player_fir(t_s *s)
{
	t_ijc	var;

	var.c = 0;
	var.i = 1;
	while (var.i < s->map.map_hei + 1)
	{
		var.j = 1;
		while (var.j < s->map.map_wid + 1)
		{
			if (ft_is_nsew(s->map.map[var.i][var.j]))
			{
				s->map.player_first[0] = var.i;
				s->map.player_first[1] = var.j;
				s->map.player_dir = s->map.map[var.i][var.j];
				s->map.map[var.i][var.j] = 'p';
				var.c++;
			}
			var.j++;
		}
		var.i++;
	}
	return (var.c);
}

int		ft_edge_player(t_s *s)
{
	if (s->map.player[0] == 1)
		return (1);
	else if (s->map.player[0] == s->map.map_hei)
		return (1);
	else if (s->map.player[1] == 1)
		return (1);
	else if (s->map.player[1] == s->map.map_wid)
		return (1);
	else
		return (0);
}

int		ft_set_player_ag(t_s *s)
{
	s->map.map[s->map.player_first[0]][s->map.player_first[1]] =
	s->map.player_dir;
	return (0);
}
