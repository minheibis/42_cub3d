/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:10:20 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 12:21:43 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_parse_map_size(t_s *s)
{
	t_cub_line	*tmp_line;

	tmp_line = s->cub_list.tmp;
	while (tmp_line != NULL && ft_parse_is_map_line(tmp_line->content))
	{
		s->map.map_hei++;
		if (tmp_line->len > s->map.map_wid)
			s->map.map_wid = tmp_line->len;
		tmp_line = tmp_line->next;
	}
	return (0);
}

int		ft_parse_map_put(t_s *s)
{
	if (!(s->map.map = (char **)malloc(sizeof(char *) * (s->map.map_hei + 3))))
		return (MALLOC_ERROR_MAP);
	s->map.map[s->map.map_hei + 2] = NULL;
	if ((s->rv = ft_parse_map_put_xrow(s, 0)))
		return (free_map(s));
	if ((s->rv = ft_parse_map_put_row(s)))
		return (free_map(s));
	if ((s->rv = ft_parse_map_put_xrow(s, s->map.map_hei + 1)))
		return (free_map(s));
	return (0);
}

int		ft_parse_map_put_xrow(t_s *s, int row)
{
	int		j;

	if (!(s->map.map[row] = (char *)malloc(sizeof(char) * (s->map.map_wid + 3))))
		return (free_map_row(s, row, MALLOC_ERROR_MAP_XROW));
	s->map.map[row][s->map.map_wid + 2] = '\0';
	j = 0;
	while (j < s->map.map_wid + 2)
	{
		s->map.map[row][j] = 'X';
		j++;
	}
	return (0);
}

int		ft_parse_map_put_row(t_s *s)
{
	int		i;

	i = 1;
	while (i < s->map.map_hei + 1)
	{
		if (!(s->map.map[i] = (char *)malloc(sizeof(char) * (s->map.map_wid + 3))))
			return (free_map_row(s, i, MALLOC_ERROR_MAP_ROW));
		s->map.map[i][0] = 'X';
		s->map.map[i][s->map.map_wid + 1] = 'X';
		s->map.map[i][s->map.map_wid + 2] = '\0';
		ft_parse_map_put_row_in(s, i);
		s->cub_list.tmp = s->cub_list.tmp->next;
		i++;
	}
	return (0);
}

int		ft_parse_map_put_row_in(t_s *s, int	i)
{
	int		j;

	j = 1;
	while (j < s->cub_list.tmp->len + 1)
	{
		s->map.map[i][j] = s->cub_list.tmp->content[j - 1];
		j++;
	}
	while (j < s->map.map_wid + 1)
	{
		s->map.map[i][j] = ' ';
		j++;
	}
	return (0);
}
