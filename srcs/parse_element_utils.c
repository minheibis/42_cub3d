/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:10:15 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 16:49:27 by hyuki            ###   ########.fr       */
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
	while (s->cub_list.tmp->content[i] == ' ')
		i++;
	ft_set_resol(s, &i, &s->map.wid_resol);
	while (s->cub_list.tmp->content[i] == ' ')
		i++;
	ft_set_resol(s, &i, &s->map.hei_resol);
	if (s->cub_list.tmp->content[i] != '\0'
		|| s->map.wid_resol <= 0 || s->map.hei_resol <= 0)
		return (SET_RESOL_ERROR);
	return (0);
}

int		ft_set_resol(t_s *s, int *i, int *resol)
{
	while (ft_isnum(s->cub_list.tmp->content[*i]))
	{
		*resol *= 10;
		*resol += (s->cub_list.tmp->content[*i] - '0');
		(*i)++;
	}
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
	while (s->cub_list.tmp->content[i] != ' ')
		i++;
	while (s->cub_list.tmp->content[i] == ' ')
		i++;
	if (!(*p_tex_path = ft_strdup(s->cub_list.tmp->content + i)))
		return (MALLOC_ERROR_TEX_PATH);
	return (0);
}
