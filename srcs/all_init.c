/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:08:51 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 14:29:22 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**get_screen_resolution
*/

int		ft_window_init(t_s *s)
{
	if (!(s->g.mlx = mlx_init()))
		return (MLX_ERROR);
	mlx_get_screen_size(s->g.mlx, &s->g.img.disp_width, &s->g.img.disp_height);
	if (s->map.wid_resol > s->g.img.disp_width && s->flag == 2)
		s->g.img.scre_width = s->g.img.disp_width;
	else
		s->g.img.scre_width = s->map.wid_resol;
	if (s->map.hei_resol > s->g.img.disp_height && s->flag == 2)
		s->g.img.scre_height = s->g.img.disp_height;
	else
		s->g.img.scre_height = s->map.hei_resol;
	if (s->flag == 2)
	{
		if (!(s->g.win = mlx_new_window(s->g.mlx, s->g.img.scre_width,
			s->g.img.scre_height, "cub3D")))
			return (free_mlx(s, WIN_ERROR));
	}
	return (0);
}

int		ft_img_init(t_s *s)
{
	if (!(s->g.img.ptr = mlx_new_image(s->g.mlx, s->g.img.scre_width,
		s->g.img.scre_height)))
		return (WIN_ERROR);
	if (!(s->g.img.data = (int *)mlx_get_data_addr(s->g.img.ptr, &s->g.img.bpp,
		&s->g.img.size_l, &s->g.img.endian)))
		return (free_img(s, WIN_ERROR));
	return (0);
}

/*
**0 and 1, and, x and y are oppposite between map and screen
*/

int		ft_player_init(t_s *s)
{
	s->g.p.posx = (double)(s->map.player_first[1] + 0.5);
	s->g.p.posy = (double)(s->map.player_first[0] + 0.5);
	ft_dir_init(s);
	return (0);
}

int		ft_wall_sp_init(t_s *s)
{
	if (!(s->g.ws.n.ptr = mlx_xpm_file_to_image(s->g.mlx,
		s->map.nor_tex_path, &s->g.ws.n.width, &s->g.ws.n.height)))
		return (XPM_FILE_ERROR);
	if (!(s->g.ws.n.data = (int *)mlx_get_data_addr(s->g.ws.n.ptr,
		&s->g.ws.n.bpp, &s->g.ws.n.size_l, &s->g.ws.n.endian)))
		return (free_xpm_n(s, XPM_FILE_ERROR));
	if (!(s->g.ws.s.ptr = mlx_xpm_file_to_image(s->g.mlx,
		s->map.sou_tex_path, &s->g.ws.s.width, &s->g.ws.s.height)))
		return (free_xpm_n(s, XPM_FILE_ERROR));
	if (!(s->g.ws.s.data = (int *)mlx_get_data_addr(s->g.ws.s.ptr,
		&s->g.ws.s.bpp, &s->g.ws.s.size_l, &s->g.ws.s.endian)))
		return (free_xpm_s(s, XPM_FILE_ERROR));
	if (!(s->g.ws.w.ptr = mlx_xpm_file_to_image(s->g.mlx,
		s->map.wes_tex_path, &s->g.ws.w.width, &s->g.ws.w.height)))
		return (free_xpm_s(s, XPM_FILE_ERROR));
	if (!(s->g.ws.w.data = (int *)mlx_get_data_addr(s->g.ws.w.ptr,
		&s->g.ws.w.bpp, &s->g.ws.w.size_l, &s->g.ws.w.endian)))
		return (free_xpm_w(s, XPM_FILE_ERROR));
	if (!(s->g.ws.e.ptr = mlx_xpm_file_to_image(s->g.mlx,
		s->map.eas_tex_path, &s->g.ws.e.width, &s->g.ws.e.height)))
		return (free_xpm_w(s, XPM_FILE_ERROR));
	if (!(s->g.ws.e.data = (int *)mlx_get_data_addr(s->g.ws.e.ptr,
		&s->g.ws.e.bpp, &s->g.ws.e.size_l, &s->g.ws.e.endian)))
		return (free_xpm_e(s, XPM_FILE_ERROR));
	return (ft_wall_sp_init_sp(s));
}

int		ft_col_init(t_s *s)
{
	s->map.flo_col_int = 0;
	s->map.flo_col_int += s->map.flo_color[0];
	s->map.flo_col_int = s->map.flo_col_int << 8;
	s->map.flo_col_int += s->map.flo_color[1];
	s->map.flo_col_int = s->map.flo_col_int << 8;
	s->map.flo_col_int += s->map.flo_color[2];
	s->map.cel_col_int = 0;
	s->map.cel_col_int += s->map.cel_color[0];
	s->map.cel_col_int = s->map.cel_col_int << 8;
	s->map.cel_col_int += s->map.cel_color[1];
	s->map.cel_col_int = s->map.cel_col_int << 8;
	s->map.cel_col_int += s->map.cel_color[2];
	return (0);
}
