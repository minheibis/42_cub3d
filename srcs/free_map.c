/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:09:42 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 12:09:43 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		free_map(t_s *s)
{
	free_NULL(s->map.map);
	return (s->rv);
}

int		free_map_row(t_s *s, int row, int rv)
{
	int	i;

	i = 0;
	while (i < row + 1)
	{
		free_NULL(s->map.map[i]);
		i++;
	}
	return (rv);
}

int		free_map_all(t_s *s, int rv)
{
	free_map_row(s, (s->map.map_hei + 1), rv);
	free_map(s);
	return (rv);
}

int		free_tex_map(t_s *s, int rv)
{
	free_tex(s, rv);
	free_map_all(s, rv);
	return (rv);
}

int		free_tex_map_sp(t_s *s, int rv)
{
	free_tex_map(s, rv);
	free_sp_all(s, rv);
	return (rv);
}
