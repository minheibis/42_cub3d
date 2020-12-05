/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub_tex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:09:37 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 16:35:22 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		free_cublist(t_s *s)
{
	t_cub_line *tmp_list;

	while (s->cub_list.start->next)
	{
		tmp_list = s->cub_list.start->next;
		free_null(s->cub_list.start->content);
		free_null(s->cub_list.start);
		s->cub_list.start = tmp_list;
	}
	free_null(s->cub_list.start->content);
	free_null(s->cub_list.start);
	return (s->rv);
}

int		free_tex(t_s *s, int rv)
{
	if (s->elem.f_no > 0)
		free_null(s->map.nor_tex_path);
	if (s->elem.f_sp > 0)
		free_null(s->map.sou_tex_path);
	if (s->elem.f_ea > 0)
		free_null(s->map.eas_tex_path);
	if (s->elem.f_we > 0)
		free_null(s->map.wes_tex_path);
	if (s->elem.f_sp > 0)
		free_null(s->map.spr_tex_path);
	return (rv);
}
