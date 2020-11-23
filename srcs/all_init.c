#include "cub3d.h"

int		ft_window_init(t_s *s)
{
	/*
	**get_screen_resolution
	*/
	s->g.mlx = mlx_init();
	mlx_get_screen_size(s->g.mlx, &s->g.img.disp_width, &s->g.img.disp_height);
	if (s->map.wid_resol > s->g.img.disp_width)
		s->g.img.scre_width = s->g.img.disp_width;
	else
		s->g.img.scre_width = s->map.wid_resol;
	if (s->map.hei_resol > s->g.img.disp_height)
		s->g.img.scre_height = s->g.img.disp_height;
	else
		s->g.img.scre_height = s->map.hei_resol;
	s->g.win = mlx_new_window(s->g.mlx, s->g.img.scre_width, s->g.img.scre_height, "cub3D");
	return (0);
}

int		ft_img_init(t_s *s)
{
	s->g.img.ptr = mlx_new_image(s->g.mlx, s->g.img.scre_width, s->g.img.scre_height);
	s->g.img.data = (int *)mlx_get_data_addr(s->g.img.ptr, &s->g.img.bpp, &s->g.img.size_l, &s->g.img.endian);
	return (0);
}

int		ft_player_init(t_s *s)
{
	//maybe +0.5?
	/*
	**x and y are oppposite
	*/
	s->g.p.posX = (double)(s->map.player_first[1] + 0.5);
	s->g.p.posY = (double)(s->map.player_first[0] + 0.5);
	ft_dir_init(s);
	return (0);
}


int		ft_wall_sp_init(t_s *s)
{
	if (!(s->g.ws.N.ptr = mlx_xpm_file_to_image(s->g.mlx, s->map.nor_tex_path, &s->g.ws.N.width, &s->g.ws.N.height)))
		return (XPM_FILE_ERROR);
	if (!(s->g.ws.N.data = (int *)mlx_get_data_addr(s->g.ws.N.ptr, &s->g.ws.N.bpp, &s->g.ws.N.size_l, &s->g.ws.N.endian)))
		return (XPM_FILE_ERROR);
	if (!(s->g.ws.S.ptr = mlx_xpm_file_to_image(s->g.mlx, s->map.sou_tex_path, &s->g.ws.S.width, &s->g.ws.S.height)))
		return (XPM_FILE_ERROR);
	if (!(s->g.ws.S.data = (int *)mlx_get_data_addr(s->g.ws.S.ptr, &s->g.ws.S.bpp, &s->g.ws.S.size_l, &s->g.ws.S.endian)))
		return (XPM_FILE_ERROR);
	if (!(s->g.ws.W.ptr = mlx_xpm_file_to_image(s->g.mlx, s->map.wes_tex_path, &s->g.ws.W.width, &s->g.ws.W.height)))
		return (XPM_FILE_ERROR);
	if (!(s->g.ws.W.data = (int *)mlx_get_data_addr(s->g.ws.W.ptr, &s->g.ws.W.bpp, &s->g.ws.W.size_l, &s->g.ws.W.endian)))
		return (XPM_FILE_ERROR);
	if (!(s->g.ws.E.ptr = mlx_xpm_file_to_image(s->g.mlx, s->map.eas_tex_path, &s->g.ws.E.width, &s->g.ws.E.height)))
		return (XPM_FILE_ERROR);
	if (!(s->g.ws.E.data = (int *)mlx_get_data_addr(s->g.ws.E.ptr, &s->g.ws.E.bpp, &s->g.ws.E.size_l, &s->g.ws.E.endian)))
		return (XPM_FILE_ERROR);
	if (!(s->g.ws.sp.ptr = mlx_xpm_file_to_image(s->g.mlx, s->map.spr_tex_path, &s->g.ws.sp.width, &s->g.ws.sp.height)))
		return (XPM_FILE_ERROR);
	if (!(s->g.ws.sp.data = (int *)mlx_get_data_addr(s->g.ws.sp.ptr, &s->g.ws.sp.bpp, &s->g.ws.sp.size_l, &s->g.ws.sp.endian)))
		return (XPM_FILE_ERROR);
	return(0);
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
