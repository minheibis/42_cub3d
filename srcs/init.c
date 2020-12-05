/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:10:03 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 16:13:41 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_init_s(t_s *s)
{
	s->rv = 0;
	if ((s->rv = ft_init_cub(s)))
		return (s->rv);
	ft_init_map(s);
	ft_init_elem_flag(s);
	return (0);
}

int		ft_init_cub(t_s *s)
{
	if (!(s->cub_list.start = (t_cub_line *)malloc(sizeof(t_cub_line))))
		return (MALLOC_ERROR_CUB_LIST_START);
	s->cub_list.start->content = NULL;
	s->cub_list.start->num = 0;
	s->cub_list.start->len = 0;
	s->cub_list.start->next = NULL;
	return (0);
}

int		ft_init_map(t_s *s)
{
	s->map.wid_resol = 0;
	s->map.hei_resol = 0;
	s->map.nor_tex_path = NULL;
	s->map.sou_tex_path = NULL;
	s->map.wes_tex_path = NULL;
	s->map.eas_tex_path = NULL;
	s->map.spr_tex_path = NULL;
	s->map.flo_color[0] = 0;
	s->map.flo_color[1] = 0;
	s->map.flo_color[2] = 0;
	s->map.cel_color[0] = 0;
	s->map.cel_color[1] = 0;
	s->map.cel_color[2] = 0;
	s->map.map = NULL;
	s->map.map_wid = 0;
	s->map.map_hei = 0;
	s->map.map_flag = 0;
	s->map.player[0] = 0;
	s->map.player[1] = 0;
	s->map.player_first[0] = 0;
	s->map.player_first[1] = 0;
	s->map.player_dir = '\0';
	s->map.sp_count = 0;
	return (0);
}

int		ft_init_elem_flag(t_s *s)
{
	s->elem.f_r = 0;
	s->elem.f_no = 0;
	s->elem.f_so = 0;
	s->elem.f_we = 0;
	s->elem.f_ea = 0;
	s->elem.f_sp = 0;
	s->elem.f_f = 0;
	s->elem.f_c = 0;
	return (0);
}
