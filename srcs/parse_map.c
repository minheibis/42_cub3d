/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:10:25 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 15:58:07 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_parse_map(t_s *s)
{
	s->cub_list.tmp = s->cub_list.start;
	while (s->map.map_flag == 0)
	{
		if ((s->rv = ft_parse_map_bef(s)))
			return (s->rv);
	}
	if (s->map.map_flag == 1)
	{
		if ((s->rv = ft_parse_map_set(s)))
			return (s->rv);
		if ((s->rv = ft_parse_map_aft(s)))
			return (free_map_all(s, s->rv));
	}
	return (0);
}

int		ft_parse_map_bef(t_s *s)
{
	while (s->cub_list.tmp->next)
	{
		if ((s->rv = ft_parse_is_map_line(s->cub_list.tmp->content)))
		{
			s->map.map_flag = 1;
			return (0);
		}
		s->cub_list.tmp = s->cub_list.tmp->next;
	}
	return (NO_MAP_FOUND);
}

int		ft_parse_map_set(t_s *s)
{
	if ((s->rv = ft_parse_map_size(s)))
		return (s->rv);
	if ((s->rv = ft_parse_map_put(s)))
		return (s->rv);
	return (0);
}

int		ft_parse_map_aft(t_s *s)
{
	while (s->cub_list.tmp)
	{
		if (s->cub_list.tmp->len != 0)
			return (NOT_EMPTY_LINE_AFTER_MAP);
		s->cub_list.tmp = s->cub_list.tmp->next;
	}
	return (0);
}
