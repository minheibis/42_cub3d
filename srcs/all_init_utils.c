/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:08:35 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 14:16:55 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_dir_init(t_s *s)
{
	if (s->map.player_dir == 'N')
	{
		s->g.p.dirx = 0.0;
		s->g.p.diry = -1.0;
		s->g.p.planeX = -0.66;
		s->g.p.planeY = 0.0;
	}
	else if (s->map.player_dir == 'S')
	{
		s->g.p.dirx = 0.0;
		s->g.p.diry = 1.0;
		s->g.p.planeX = 0.66;
		s->g.p.planeY = 0.0;
	}
	else
		return (ft_dir_init_ew(s));
	return (0);
}

int		ft_dir_init_ew(t_s *s)
{
	if (s->map.player_dir == 'E')
	{
		s->g.p.dirx = 1.0;
		s->g.p.diry = 0.0;
		s->g.p.planeX = 0.0;
		s->g.p.planeY = -0.66;
	}
	else if (s->map.player_dir == 'W')
	{
		s->g.p.dirx = -1.0;
		s->g.p.diry = 0.0;
		s->g.p.planeX = 0.0;
		s->g.p.planeY = 0.66;
	}
	return (0);
}

int		ft_sp_init(t_s *s)
{
	s->g.sp_i.zbuff = NULL;
	s->g.sp_i.sp_x = NULL;
	s->g.sp_i.sp_y = NULL;
	s->g.sp_i.spord = NULL;
	s->g.sp_i.spdist = NULL;
	return (0);
}

int		ft_wall_sp_init_sp(t_s *s)
{
	if (!(s->g.ws.sp.ptr = mlx_xpm_file_to_image(s->g.mlx,
		s->map.spr_tex_path, &s->g.ws.sp.width, &s->g.ws.sp.height)))
		return (free_xpm_e(s, XPM_FILE_ERROR));
	if (!(s->g.ws.sp.data = (int *)mlx_get_data_addr(s->g.ws.sp.ptr,
		&s->g.ws.sp.bpp, &s->g.ws.sp.size_l, &s->g.ws.sp.endian)))
		return (free_xpm_sp(s, XPM_FILE_ERROR));
	return (0);
}
