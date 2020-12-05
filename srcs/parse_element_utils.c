/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:10:15 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 16:26:59 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_parse_r(t_s *s)
{
	int		i;

	if (s->elem.f_r != 0)
		return (NOT_ONE_ELEMENT_ERROR);
	else
		s->elem.f_r++;
	i = 1;
	while(s->cub_list.tmp->content[i] == ' ')
		i++;
	while (ft_isnum(s->cub_list.tmp->content[i]))
	{
		s->map.wid_resol *= 10;
		s->map.wid_resol += (s->cub_list.tmp->content[i] - '0');
		i++;
	}
	while(s->cub_list.tmp->content[i] == ' ')
		i++;
	while (ft_isnum(s->cub_list.tmp->content[i]))
	{
		s->map.hei_resol *= 10;
		s->map.hei_resol += (s->cub_list.tmp->content[i] - '0');
		i++;
	}
	if (s->cub_list.tmp->content[i] != '\0' || s->map.wid_resol <= 0 || s->map.hei_resol <= 0)
		return (SET_RESOL_ERROR);
	return (0);
}

int		ft_parse_tex(t_s *s, int *tex_flag, char **p_tex_path)
{
	int		i;

	if (*tex_flag != 0)
		return (NOT_ONE_ELEMENT_ERROR);
	else
		(*tex_flag)++;
	i = 0;
	while(s->cub_list.tmp->content[i] != ' ')
		i++;
	while(s->cub_list.tmp->content[i] == ' ')
		i++;
	if(!(*p_tex_path = ft_strdup(s->cub_list.tmp->content + i)))
		return (MALLOC_ERROR_TEX_PATH);
	return (0);
}

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
		if (j != 0 && s->cub_list.tmp->content[i] == ',')
			i++;
		else if (j != 0)
			return (SET_COLOR_ERROR);
		while (s->cub_list.tmp->content[i] == ' ')
			i++;
		while (ft_isnum(s->cub_list.tmp->content[i]))
		{
			p_color_path[j] *= 10;
			p_color_path[j] += (s->cub_list.tmp->content[i] - '0');
			if (p_color_path[j] > 255)
				return (SET_COLOR_ERROR);
			i++;
		}
		j++;
	}
	if (s->cub_list.tmp->content[i] != '\0')
		return (SET_COLOR_ERROR);
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
