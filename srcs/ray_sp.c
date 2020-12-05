/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:10:30 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 12:22:16 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_ray_sp(t_s *s)
{
	ft_sort_sp(s);
	ft_draw_sp(s);
	return (0);
}

int		ft_sort_sp(t_s *s)
{
	ft_sort_sp_calc(s);
	ft_sort_sp_sort(s);
	return (0);
}

int		ft_draw_sp(t_s *s)
{
	int	i;

	i = 0;
	while (i < s->map.sp_count)
	{
		ft_draw_sp_one(s, i);
		i++;
	}
	return (0);
}
