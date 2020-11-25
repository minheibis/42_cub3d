#ifndef __CUB3D_H_INCLUDED__
#define __CUB3D_H_INCLUDED__

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "mlx.h"
#include "key_linux.h"

//delet at last
#include <stdio.h>

# define MAX_FD 256
# define BUFFER_SIZE 256
/*
**define_errors
*/
# define INPUT_NUM_ERROR 1
# define CUB_NAME_ERROR 2
# define NOT_SAVE 3
# define FILE_OPEN_ERROR 4
# define GNL_ERROR 5
# define MALLOC_ERROR 6
# define SET_COLOR_ERROR 7
# define NO_MAP_FOUND 8
# define NOT_EMPTY_LINE_AFTER_MAP 9
# define NOT_SURROUNEDED_BY_WALLS 10
# define NOT_ONE_PLAYER 11
# define FAIL_INIT 12
# define XPM_FILE_ERROR 13
# define MALLOC_ERROR_ZBUFF 14
# define MALLOC_ERROR_SP_X 15
# define MALLOC_ERROR_SP_Y 16
# define MALLOC_ERROR_SPORD 17
# define MALLOC_ERROR_SPDIST 18
# define BMP_FILE_OPEN_ERROR 19
# define MALLOC_ERROR_BMP_LINE 20
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
#define moveSpeed		0.3
#define rotSpeed		0.1
/*
**for bitmap
*/
#define FILEHEADERSIZE 14
#define INFOHEADERSIZE 40
#define HEADERSIZE (FILEHEADERSIZE+INFOHEADERSIZE)


typedef struct	s_cub_line
{
	char				*content;
	int					num;
	int					len;
	struct s_cub_line	*next;
}				t_cub_line;

typedef struct	s_cub_list
{
	t_cub_line	*start;
	t_cub_line	*tmp;
}				t_cub_list;

typedef struct	s_map
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
}				t_map;

typedef struct	s_img
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
}				t_img;

typedef struct	s_player
{
	/*
	**x and y start position
	*/
	double	posX;
	double	posY;
	/*
	**initial direction vector
	*/
	double	dirX;
	double	dirY;
	/*
	**camera plane(vector)
	*/
	double	planeX;
	double	planeY;
	/*
	**old dir and plane for rotation
	*/
	double	oldDirX;
	double	oldPlaneX;
}				t_player;

typedef struct	s_ray
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
}				t_ray;

typedef struct	s_ws_img
{
	t_img	now;
	t_img	N;
	t_img	S;
	t_img	W;
	t_img	E;
	t_img	sp;
}				t_ws_img;


typedef struct	s_hit_calc
{
	/*
	**which box of the map we are in
	*/
	int		mapX;
	int		mapY;
	/*
	**length of ray from current position to next x or y-side
	*/
	double	sideDistX;
	double	sideDistY;
	/*
	**length of ray from one x or y-side to next x or y-side
	*/
	double	deltaDistX;
	double	deltaDistY;
	double	prepWallDist;
	/*
	**what direction to step in x or y-direction (either -1 or -1)
	*/
	int		stepX;
	int		stepY;
	/*
	**was there a wall hit?
	*/
	int		hit;
	/*
	**was a NS or a EW wall hit?
	*/
	int		side;
}				t_hit_calc;

typedef struct	s_draw_calc
{
	/*
	**Calculate height of line to draw on screen
	*/
	int		lineH;
	/*
	**Calculate lowest and highest pixel to fill in current stripe
	*/
	int		drawS;
	int		drawE;
	/*
	**where exactly the wall was hit
	*/
	double	wallX;
	/*
	**x coordinate on the texture
	*/
	int		texX;
	/*
	**y coordinate on the texture
	*/
	int		texY;
	/*
	**how much to increase the texture coordinate per screen pixel
	*/
	double	step;
	/*
	**starting texture coordinate
	*/
	double	texPos;
	/*
	**choose wall color
	*/
	int		color;
}				t_draw_calc;

typedef struct	s_sp_info
{
	/*
	**1d Zbuffer
	*/
	double		*ZBuff;
	double		*sp_x;
	double		*sp_y;
	/*
	**arrays used to sort the sprites
	*/
	int			*spOrd;
	double		*spDist;
	/*
	**sprite position relative to camera
	*/
	double		spX;
	double		spY;
	/*
	**transform sprite with inverse camera matirix
	*/
	double		invDet;
	double		trX;
	double		trY;
	int			spScX;
	/*
	**calculate height of the sprite on screen
	*/
	int			spH;
	/*
	**calculate lowest and highest pixel to fill in current stripe
	*/
	int			drawSY;
	int			drawEY;
	/*
	**calculate width of the sprite
	*/
	int			spW;
	int			drawSX;
	int			drawEX;
	/*
	**loop through every vertical stripe of the sprite on screen
	*/
	int			stripe;
}				t_sp_info;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_player	p;
	t_ray		r;
	t_ws_img	ws;
	t_hit_calc	h_c;
	t_draw_calc	d_c;
	t_sp_info	sp_i;
}				t_game;

typedef struct	s_ij
{
	int		i;
	int		j;
}				t_ij;

typedef struct	s_xy
{
	int		x;
	int		y;
}				t_xy;

typedef struct	s_ijc
{
	int		i;
	int		j;
	int		c;
}				t_ijc;

typedef struct	s_s
{
	int			rv;
	t_cub_list	cub_list;
	t_map		map;
	t_game		g;
	int			flag;
}				t_s;
/*
**cub_list_utils.c
*/
int		set_next_cub_list(t_s *s);
/*
**cub3d.c
*/
int		ft_parse_to_draw(char *cub_file, int flag);
int		main(void);
/*
**error.c
*/
int		ft_error(int rv);
/*
**get_next_line_utils.c
*/
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
/*
**get_next_line.c
*/
int		free_return(char *s, int rv);
int		set_fd(char **rest_fd, int fd);
int		set_line(char **rest_fd, char **line);
int		get_next_line(int fd, char **line);
/*
**init.c
*/
int		init_s(t_s *s);
int		init_cub(t_s *s);
int		init_map(t_s *s);
/*
**input_check.c
*/
int		ft_save_check(char *arg, char *save);
int		ft_cub_check(char *arg, char *cub);
/*
**read_cub.c
*/
int		ft_read_cub(t_s *s, char *cub_file);
int		ft_parse_cub(t_s *s);
/*
**parse_element.c
*/
int		ft_parse_element(t_s *s);
int		ft_parse_R(t_s *s);
int		ft_parse_tex(t_s *s, char **p_tex_path);
int		ft_parse_color(t_s *s, int *p_color_path);
/*
**parse_map.c
*/
int		ft_parse_map(t_s *s);
int		ft_parse_map_bef(t_s *s);
int		ft_parse_map_set(t_s *s);
int		ft_parse_map_aft(t_s *s);
/*
**parse_map_set.c
*/
int		ft_parse_map_size(t_s *s);
int		ft_parse_map_put(t_s *s);
int		ft_parse_map_put_xrow(t_s *s, int row);
int		ft_parse_map_put_row_in(t_s *s, int	i);
int		ft_parse_map_put_row(t_s *s);
/*
**parse_map_utils.c
*/
int		ft_parse_is_map_line(char *cub_line);
/*
**ft_isnum.c
*/
int		ft_isnum(char c);
/*
**check_map.c
*/
int		ft_check_map(t_s *s);
int		ft_find_fake_player(t_s *s);
int		ft_find_wall(t_s *s, int flag_row);
/*
**check_map_utils.c
*/
int		ft_is_NSEW(char c);
int		ft_find_player_fir(t_s *s);
int		ft_edge_player(t_s *s);
int		ft_set_player_ag(t_s *s);
/*
**find_wall.c
*/
int		ft_find_wall_row_for(t_s *s);
int		ft_find_wall_row_bac(t_s *s);
int		ft_find_wall_col_for(t_s *s);
int		ft_find_wall_col_bac(t_s *s);
/*
**check_p.c
*/
int		ft_check_p_row(t_s *s, int i, int j);
int		ft_check_p_col(t_s *s, int i, int j);
/*
**check_p_utils.c
*/
int		ft_map_space(char c);
int		ft_map_item(t_s *s, char c);
int		ft_map_player(char c);
int		ft_map_fake_wall(char c);
/*
**draw_map.c
*/
int		ft_draw_map(t_s *s);
int		ft_all_init(t_s *s);
/*
**deal_key.c
*/
int		ft_deal_key(int key_code, t_s *s);
int		ft_deal_key_AD(int key_code, t_s *s);
int		ft_deal_key_RL(int key_code, t_s *s);
/*
**deal_key_utils.c
*/
int		ft_map_in(char c);
/*
**all_init.c
*/
int		ft_window_init(t_s *s);
int		ft_img_init(t_s *s);
int		ft_player_init(t_s *s);
int		ft_wall_sp_init(t_s *s);
int		ft_col_init(t_s *s);
/*
**all_init_utils.c
*/
int		ft_dir_init(t_s *s);
int		ft_dir_init_EW(t_s *s);

/*
**main_loop.c
*/
int		ft_main_loop(t_s *s);
int		ft_ray_wall(t_s *s);
/*
**main_loop_utils.c
*/
int		reset_img(t_s *s);
/*
**ray_wall_x.c
*/
int		ft_ray_wall_x(t_s *s, int x);
int		ft_calc_pos(t_s *s, int x);
int		ft_calc_hit(t_s *s);
int		ft_calc_line(t_s *s);
int		ft_draw_line(t_s *s, int x);
/*
**calc_hit_utils.c
*/
int		ft_calc_hit_init(t_s *s);
int		ft_calc_hit_DDA(t_s *s);
/*
**draw_line_utils.c
*/
int		to_coord(int x, int y, t_s *s);
int		ft_decide_wall(t_s *s);
int		ft_draw_line_calc(t_s *s);
int		ft_draw_line_draw(t_s *s, int x);
/*
**parse_sp.c
*/
int		ft_parse_sp(t_s *s);
int		ft_search_sp(t_s *s);
/*
**ray_sp.c
*/
int		ft_ray_sp(t_s *s);
int		ft_sort_sp(t_s *s);
int		ft_draw_sp(t_s *s);
/*
**sort_sp.c
*/
int		ft_sort_sp_calc(t_s *s);
int		ft_sort_sp_sort(t_s *s);
/*
**draw_sp_one.c
*/
int		ft_draw_sp_one(t_s *s, int i);
int		ft_draw_sp_one_pos(t_s *s, int i);
int		ft_draw_sp_one_HW(t_s *s);
int		ft_draw_sp_one_draw(t_s *s);
/*
**bitmap.c
*/
int		ft_write_bmp(char *filename, t_s *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);


//test_utils.c delete after
void	ft_show_map(t_s *s);

#endif