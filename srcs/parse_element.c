/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:10:18 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 15:53:31 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_parse_element(t_s *s)
{
	while (s->cub_list.tmp->next)
	{
		if (s->cub_list.tmp->content[0] == 'R' && s->cub_list.tmp->content[1] == ' ')
			s->rv = ft_parse_r(s);
		else if (s->cub_list.tmp->content[0] == 'N' && s->cub_list.tmp->content[1] == 'O' && s->cub_list.tmp->content[2] == ' ')
			s->rv = ft_parse_tex(s, &(s->elem.f_no), &(s->map.nor_tex_path));
		else if (s->cub_list.tmp->content[0] == 'S' && s->cub_list.tmp->content[1] == 'O' && s->cub_list.tmp->content[2] == ' ')
			s->rv = ft_parse_tex(s, &(s->elem.f_so), &(s->map.sou_tex_path));
		else if (s->cub_list.tmp->content[0] == 'W' && s->cub_list.tmp->content[1] == 'E' && s->cub_list.tmp->content[2] == ' ')
			s->rv = ft_parse_tex(s, &(s->elem.f_we), &(s->map.wes_tex_path));
		else if (s->cub_list.tmp->content[0] == 'E' && s->cub_list.tmp->content[1] == 'A' && s->cub_list.tmp->content[2] == ' ')
			s->rv = ft_parse_tex(s, &(s->elem.f_ea), &(s->map.eas_tex_path));
		else if (s->cub_list.tmp->content[0] == 'S' && s->cub_list.tmp->content[1] == ' ')
			s->rv = ft_parse_tex(s, &(s->elem.f_sp), &(s->map.spr_tex_path));
		else if (s->cub_list.tmp->content[0] == 'F' && s->cub_list.tmp->content[1] == ' ')
			s->rv = ft_parse_color(s, &(s->elem.f_f), &(s->map.flo_color[0]));
		else if (s->cub_list.tmp->content[0] == 'C' && s->cub_list.tmp->content[1] == ' ')
			s->rv = ft_parse_color(s, &(s->elem.f_c), &(s->map.cel_color[0]));
		else if (s->cub_list.tmp->content[0] != '\0' && ft_parse_is_map_line(s->cub_list.tmp->content) == 0)
			s->rv = INVALID_LINE_ERROR;
		if (s->rv != 0)
			return (free_tex(s, s->rv));
		s->cub_list.tmp = s->cub_list.tmp->next;
	}
	if ((s->rv = ft_check_set_element(s)))
		return (free_tex(s, s->rv));
	return (0);
}

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
