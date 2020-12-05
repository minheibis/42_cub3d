/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:10:18 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 16:41:52 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_parse_element(t_s *s)
{
	while (s->cub_list.tmp->next)
	{
		ft_parse_element_tex(s);
		if (s->rv != 0)
			return (free_tex(s, s->rv));
		s->cub_list.tmp = s->cub_list.tmp->next;
	}
	if ((s->rv = ft_check_set_element(s)))
		return (free_tex(s, s->rv));
	return (0);
}

int		ft_parse_element_tex(t_s *s)
{
	if (s->cub_list.tmp->content[0] == 'R'
		&& s->cub_list.tmp->content[1] == ' ')
		s->rv = ft_parse_r(s);
	else if (s->cub_list.tmp->content[0] == 'N'
		&& s->cub_list.tmp->content[1] == 'O'
		&& s->cub_list.tmp->content[2] == ' ')
		s->rv = ft_parse_tex(s, &(s->elem.f_no), &(s->map.nor_tex_path));
	else if (s->cub_list.tmp->content[0] == 'S'
		&& s->cub_list.tmp->content[1] == 'O'
		&& s->cub_list.tmp->content[2] == ' ')
		s->rv = ft_parse_tex(s, &(s->elem.f_so), &(s->map.sou_tex_path));
	else if (s->cub_list.tmp->content[0] == 'W'
		&& s->cub_list.tmp->content[1] == 'E'
		&& s->cub_list.tmp->content[2] == ' ')
		s->rv = ft_parse_tex(s, &(s->elem.f_we), &(s->map.wes_tex_path));
	else if (s->cub_list.tmp->content[0] == 'E'
		&& s->cub_list.tmp->content[1] == 'A'
		&& s->cub_list.tmp->content[2] == ' ')
		s->rv = ft_parse_tex(s, &(s->elem.f_ea), &(s->map.eas_tex_path));
	else if (s->cub_list.tmp->content[0] == 'S'
		&& s->cub_list.tmp->content[1] == ' ')
		s->rv = ft_parse_tex(s, &(s->elem.f_sp), &(s->map.spr_tex_path));
	else
		return (ft_parse_element_col(s));
	return (0);
}

int		ft_parse_element_col(t_s *s)
{
	if (s->cub_list.tmp->content[0] == 'F'
		&& s->cub_list.tmp->content[1] == ' ')
		s->rv = ft_parse_color(s, &(s->elem.f_f), &(s->map.flo_color[0]));
	else if (s->cub_list.tmp->content[0] == 'C'
		&& s->cub_list.tmp->content[1] == ' ')
		s->rv = ft_parse_color(s, &(s->elem.f_c), &(s->map.cel_color[0]));
	else if (s->cub_list.tmp->content[0] != '\0'
		&& ft_parse_is_map_line(s->cub_list.tmp->content) == 0)
		s->rv = INVALID_LINE_ERROR;
	return (0);
}
