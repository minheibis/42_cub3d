/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element_utils_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:44:07 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 16:59:11 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_parse_color(t_s *s, int *col_flag, int *p_color_path)
{
	int		i;
	int		j;

	if (*col_flag != 0)
		return (NOT_ONE_ELEMENT_ERROR);
	else
		(*col_flag)++;
	i = 1;
	j = 0;
	while (j < 3)
	{
		if ((s->rv = ft_set_color(s, j, &i, p_color_path)))
			return (s->rv);
		j++;
	}
	if (s->cub_list.tmp->content[i] != '\0')
		return (SET_COLOR_ERROR);
	return (0);
}

int		ft_set_color(t_s *s, int j, int *i, int *p_color_path)
{
	if (j != 0 && s->cub_list.tmp->content[*i] == ',')
		(*i)++;
	else if (j != 0)
		return (SET_COLOR_ERROR);
	while (s->cub_list.tmp->content[*i] == ' ')
		(*i)++;
	while (ft_isnum(s->cub_list.tmp->content[*i]))
	{
		p_color_path[j] *= 10;
		p_color_path[j] += (s->cub_list.tmp->content[*i] - '0');
		if (p_color_path[j] > 255)
			return (SET_COLOR_ERROR);
		(*i)++;
	}
	return (0);
}

int		ft_check_set_element(t_s *s)
{
	if (s->elem.f_r != 1)
		return (NOT_ONE_ELEMENT_ERROR);
	if (s->elem.f_no != 1)
		return (NOT_ONE_ELEMENT_ERROR);
	if (s->elem.f_so != 1)
		return (NOT_ONE_ELEMENT_ERROR);
	if (s->elem.f_we != 1)
		return (NOT_ONE_ELEMENT_ERROR);
	if (s->elem.f_ea != 1)
		return (NOT_ONE_ELEMENT_ERROR);
	if (s->elem.f_sp != 1)
		return (NOT_ONE_ELEMENT_ERROR);
	if (s->elem.f_f != 1)
		return (NOT_ONE_ELEMENT_ERROR);
	if (s->elem.f_c != 1)
		return (NOT_ONE_ELEMENT_ERROR);
	return (0);
}
