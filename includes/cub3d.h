/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 13:00:59 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/09 13:54:10 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "key_linux.h"

# define MAX_FD 256
# define BUFFER_SIZE 128

/*
**define_errors
*/
# define INPUT_NUM_ERROR 1
# define CUB_NAME_ERROR 2
# define NOT_SAVE 3
# define MALLOC_ERROR_CUB_LIST_START 4
# define FILE_OPEN_ERROR 5
# define GNL_ERROR 6
# define MALLOC_ERROR_TMP_CONTENT 7
# define MALLOC_ERROR_NEXT_CUB_LIST 8
# define SET_RESOL_ERROR 9
# define NOT_ONE_ELEMENT_ERROR 10
# define INVALID_LINE_ERROR 11
# define MALLOC_ERROR_TEX_PATH 12
# define SET_COLOR_ERROR 13
# define NO_MAP_FOUND 14
# define LARGE_MAP_ERROR 15
# define MALLOC_ERROR_MAP 16
# define MALLOC_ERROR_MAP_XROW 17
# define MALLOC_ERROR_MAP_ROW 18
# define NOT_EMPTY_LINE_AFTER_MAP 19
# define NOT_SURROUNEDED_BY_WALLS 20
# define NOT_ONE_PLAYER 21
# define FAIL_INIT 22
# define MLX_ERROR 23
# define WIN_ERROR 24
# define XPM_FILE_ERROR 25
# define MALLOC_ERROR_ZBUFF 26
# define MALLOC_ERROR_SP_X 27
# define MALLOC_ERROR_SP_Y 28
# define MALLOC_ERROR_SPORD 29
# define MALLOC_ERROR_SPDIST 30
# define BMP_FILE_OPEN_ERROR 31
# define MALLOC_ERROR_BMP_LINE 32
# define BMP_HEAD_WRITE_ERROR 33
# define BMP_RGB_WRITE_ERROR 34

/*
**for check_p
*/
# define IS_MAP 0
# define IS_WALL 1
# define NO_WALL 2

/*
**for draw_map
*/
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define SPEED		0.3
# define ROTSPEED		0.1

/*
**for bitmap
*/
# define FILEHEADERSIZE 14
# define INFOHEADERSIZE 40
# define HEADERSIZE 54

typedef struct		s_cub_line
{
	char				*content;
	int					num;
	int					len;
	struct s_cub_line	*next;
}					t_cub_line;

typedef struct		s_cub_list
{
	t_cub_line	*start;
	t_cub_line	*tmp;
}					t_cub_list;

typedef struct		s_elem_flag
{
	int		f_r;
	int		f_no;
	int		f_so;
	int		f_we;
	int		f_ea;
	int		f_sp;
	int		f_f;
	int		f_c;
}					t_elem_flag;

typedef struct		s_map
{
	int		wid_resol;
	int		hei_resol;
	char	*nor_tex_path;
	char	*sou_tex_path;
	char	*wes_tex_path;
	char	*eas_tex_path;
	char	*spr_tex_path;
	int		flo_color[3];
	int		cel_color[3];
	int		flo_col_int;
	int		cel_col_int;
	char	**map;
	char	**tmp_map;
	int		map_wid;
	int		map_hei;
	int		map_flag;
	int		player[2];
	int		player_first[2];
	char	player_dir;
	int		sp_count;
}					t_map;

typedef struct		s_img
{
	void	*ptr;
	int		*data;
	int		width;
	int		height;
	int		disp_width;
	int		disp_height;
	int		scre_width;
	int		scre_height;
	int		size_l;
	int		bpp;
	int		endian;
}					t_img;

typedef struct		s_player
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	olddirx;
	double	oldplanex;
}					t_player;

typedef struct		s_ray
{
	double	camerax;
	double	raydirx;
	double	raydiry;
}					t_ray;

typedef struct		s_ws_img
{
	t_img	now;
	t_img	n;
	t_img	s;
	t_img	w;
	t_img	e;
	t_img	sp;
}					t_ws_img;

typedef struct		s_hit_calc
{
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	prepwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
}					t_hit_calc;

typedef struct		s_draw_calc
{
	int		lineh;
	int		draws;
	int		drawe;
	double	wallx;
	int		texx;
	int		texy;
	double	step;
	double	texpos;
	int		color;
}					t_draw_calc;

typedef struct		s_sp_info
{
	double		*zbuff;
	double		*sp_x;
	double		*sp_y;
	int			*spord;
	double		*spdist;
	double		spx;
	double		spy;
	double		invdet;
	double		trx;
	double		try;
	int			spscx;
	int			sph;
	int			drawsy;
	int			drawey;
	int			spw;
	int			drawsx;
	int			drawex;
	int			stripe;
}					t_sp_info;

typedef struct		s_game
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_player		p;
	t_ray			r;
	t_ws_img		ws;
	t_hit_calc		h_c;
	t_draw_calc		d_c;
	t_sp_info		sp_i;
}					t_game;

typedef struct		s_bitmap
{
	int				fd;
	int				real_width;
	unsigned char	*bmp_line_data;
	unsigned char	header_buf[HEADERSIZE];
	unsigned int	file_size;
	unsigned int	reserved;
	unsigned int	offset_to_data;
	unsigned int	info_header_size;
	unsigned int	bit_width;
	unsigned int	bit_height;
	unsigned short	planes;
	unsigned short	color;
	unsigned int	compress;
	unsigned int	data_size;
	unsigned int	xppm;
	unsigned int	yppm;
	unsigned int	pallete_num;
	unsigned int	important;
}					t_bitmap;

typedef struct		s_ij
{
	int		i;
	int		j;
}					t_ij;

typedef struct		s_xy
{
	int		x;
	int		y;
}					t_xy;

typedef struct		s_ijc
{
	int		i;
	int		j;
	int		c;
}					t_ijc;

typedef struct		s_read_cub
{
	int			fd;
	int			rv;
	char		*line;
}					t_read_cub;

typedef struct		s_s
{
	int				rv;
	t_cub_list		cub_list;
	t_map			map;
	t_elem_flag		elem;
	t_game			g;
	t_bitmap		b;
	int				flag;
}					t_s;
/*
**cub_list_utils.c
*/
int					ft_set_next_cub_list(t_s *s);
/*
**cub3d.c
*/
int					ft_parse_to_draw(char *cub_file, int flag);
int					main(int argc, char **argv);
/*
**error.c
*/
int					ft_error(int rv);
int					ft_error_2(int rv);
int					ft_error_3(int rv);
/*
**get_next_line_utils.c
*/
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *src);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *str);
char				*ft_strchr(const char *s, int c);
/*
**get_next_line.c
*/
int					set_fd(char **rest_fd, int fd);
int					set_line(char **rest_fd, char **line);
int					get_next_line(int fd, char **line);
/*
**init.c
*/
int					ft_init_s(t_s *s);
int					ft_init_cub(t_s *s);
int					ft_init_map(t_s *s);
int					ft_init_elem_flag(t_s *s);
/*
**input_check.c
*/
int					ft_save_check(char *arg, char *save);
int					ft_cub_check(char *arg, char *cub);
/*
**read_cub.c
*/
int					ft_read_cub(t_s *s, char *cub_file);
int					ft_parse_cub(t_s *s);
/*
**parse_element.c
*/
int					ft_parse_element(t_s *s);
int					ft_parse_element_tex(t_s *s);
int					ft_parse_element_col(t_s *s);
/*
**parse_element_utils.c
*/
int					ft_parse_r(t_s *s);
int					ft_set_resol(t_s *s, int *i, int *resol);
int					ft_parse_tex(t_s *s, int *tex_flag, char **p_tex_path);
/*
**parse_element_utils_2.c
*/
int					ft_parse_color(t_s *s, int *col_flag, int *p_color_path);
int					ft_set_color(t_s *s, int j, int *i, int *p_color_path);
int					ft_check_set_element(t_s *s);
/*
**parse_map.c
*/
int					ft_parse_map(t_s *s);
int					ft_parse_map_bef(t_s *s);
int					ft_parse_map_set(t_s *s);
int					ft_parse_map_aft(t_s *s);
/*
**parse_map_set.c
*/
int					ft_parse_map_size(t_s *s);
int					ft_parse_map_put(t_s *s);
int					ft_parse_map_put_xrow(t_s *s, int row);
int					ft_parse_map_put_row_in(t_s *s, int	i);
int					ft_parse_map_put_row(t_s *s);
/*
**parse_map_utils.c
*/
int					ft_parse_is_map_line(char *cub_line);
int					ft_parse_is_map_letter(char c);
/*
**ft_isnum.c
*/
int					ft_isnum(char c);
/*
**check_map.c
*/
int					ft_check_map(t_s *s);
int					ft_find_fake_player(t_s *s);
int					ft_find_wall(t_s *s, int flag_row);
/*
**check_map_utils.c
*/
int					ft_is_nsew(char c);
int					ft_find_player_fir(t_s *s);
int					ft_edge_player(t_s *s);
int					ft_set_player_ag(t_s *s);
/*
**find_wall.c
*/
int					ft_find_wall_row_for(t_s *s);
int					ft_find_wall_row_bac(t_s *s);
int					ft_find_wall_col_for(t_s *s);
int					ft_find_wall_col_bac(t_s *s);
/*
**check_p.c
*/
int					ft_check_p_row(t_s *s, int i, int j);
int					ft_check_p_col(t_s *s, int i, int j);
int					ft_check_cell(t_s *s, int i, int j);
int					ft_check_cell_around(t_s *s, int i, int j);
/*
**check_p_utils.c
*/
int					ft_map_space(char c);
int					ft_map_item(t_s *s, char c);
int					ft_map_player(char c);
int					ft_map_fake_wall(char c);
/*
**draw_map.c
*/
int					ft_draw_map(t_s *s);
int					ft_all_init(t_s *s);
/*
**deal_key.c
*/
int					ft_deal_key(int key_code, t_s *s);
int					ft_deal_key_s(int key_code, t_s *s);
int					ft_deal_key_ad(int key_code, t_s *s);
/*
**deal_key_2.c
*/
int					ft_deal_key_rl(int key_code, t_s *s);
int					ft_deal_key_l(int key_code, t_s *s);
/*
**deal_key_utils.c
*/
int					ft_map_in(char c);
/*
**all_init.c
*/
int					ft_window_init(t_s *s);
int					ft_img_init(t_s *s);
int					ft_player_init(t_s *s);
int					ft_wall_sp_init(t_s *s);
int					ft_col_init(t_s *s);
/*
**all_init_utils.c
*/
int					ft_dir_init(t_s *s);
int					ft_dir_init_ew(t_s *s);
int					ft_sp_init(t_s *s);
int					ft_wall_sp_init_sp(t_s *s);
/*
**main_loop.c
*/
int					ft_main_loop(t_s *s);
int					ft_ray_wall(t_s *s);
/*
**ray_wall_x.c
*/
int					ft_ray_wall_x(t_s *s, int x);
int					ft_calc_pos(t_s *s, int x);
int					ft_calc_hit(t_s *s);
int					ft_calc_line(t_s *s);
int					ft_draw_line(t_s *s, int x);
/*
**calc_hit_utils.c
*/
int					ft_calc_hit_init(t_s *s);
int					ft_calc_hit_init_2(t_s *s);
int					ft_calc_hit_dda(t_s *s);
/*
**draw_line_utils.c
*/
int					to_coord(int x, int y, t_s *s);
int					ft_decide_wall(t_s *s);
int					ft_draw_line_calc(t_s *s);
int					ft_draw_line_draw(t_s *s, int x);
/*
**parse_sp.c
*/
int					ft_parse_sp(t_s *s);
int					ft_search_sp(t_s *s);
/*
**ray_sp.c
*/
int					ft_ray_sp(t_s *s);
int					ft_sort_sp(t_s *s);
int					ft_draw_sp(t_s *s);
/*
**sort_sp.c
*/
int					ft_sort_sp_calc(t_s *s);
int					ft_sort_sp_sort(t_s *s);
/*
**draw_sp_one.c
*/
int					ft_draw_sp_one(t_s *s, int i);
int					ft_draw_sp_one_pos(t_s *s, int i);
int					ft_draw_sp_one_hw(t_s *s);
int					ft_draw_sp_one_draw(t_s *s);
int					ft_draw_sp_one_draw_y(t_s *s, int y);
/*
**draw_sp_one_utils.c
*/
int					ft_check_size_xy(int *check, int min, int max);
/*
**bitmap.c
*/
int					ft_write_bmp(char *filename, t_s *s);
int					ft_bmp_init(t_s *s);
int					ft_bmp_head_set(t_s *s);
int					ft_bmp_rgb_set(t_s *s);
int					ft_bmp_rgb_set_line(int i, t_s *s);
/*
**bitmap_utils.c
*/
void				*ft_memcpy(void *dest, void *src, size_t n);
/*
**free_utils.c
*/
void				free_null(void *p);
int					free_return(void *p, int rv);
/*
**free_cub_tex.c
*/
int					free_cublist(t_s *s);
int					free_tex(t_s *s, int rv);
/*
**free_map.c
*/
int					free_map(t_s *s);
int					free_map_row(t_s *s, int row, int rv);
int					free_map_all(t_s *s, int rv);
int					free_tex_map(t_s *s, int rv);
int					free_tex_map_sp(t_s *s, int rv);
/*
**free_xpm.c
*/
int					free_xpm_n(t_s *s, int rv);
int					free_xpm_s(t_s *s, int rv);
int					free_xpm_w(t_s *s, int rv);
int					free_xpm_e(t_s *s, int rv);
int					free_xpm_sp(t_s *s, int rv);
/*
**free_sp.c
*/
int					free_sp_zbuff(t_s *s, int rv);
int					free_sp_x(t_s *s, int rv);
int					free_sp_y(t_s *s, int rv);
int					free_spord(t_s *s, int rv);
int					free_sp_all(t_s *s, int rv);
/*
**free_mlx.c
*/
int					free_mlx(t_s *s, int rv);
int					free_wind(t_s *s, int rv);
int					free_img(t_s *s, int rv);
/*
**free_exit.c
*/
int					free_xpm_img(t_s *s, int rv);
int					free_exit(t_s *s, int rv);
int					free_for_bmp(t_s *s, int rv);

#endif
