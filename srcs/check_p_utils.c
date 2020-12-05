/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_p_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:09:05 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 15:57:49 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_map_space(char c)
{
	if (c == '0' || c == 'p' || c == ' ')
		return (1);
	else
		return (0);
}

int		ft_map_item(t_s *s, char c)
{
	if (c == '2')
	{
		s->map.sp_count++;
		return (1);
	}
	else if (c == 'd')
		return (1);
	else
		return (0);
}

int		ft_map_player(char c)
{
	if (c == 'p' || c == 'd')
		return (1);
	else
		return (0);
}

int		ft_map_fake_wall(char c)
{
	if (c == 'w' || c == 'y')
		return (1);
	else
		return (0);
}
