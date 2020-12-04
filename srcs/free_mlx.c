#include "cub3d.h"

int		free_mlx(t_s *s, int rv)
{
	free_NULL(s->g.mlx);
	return (rv);
}

int		free_wind(t_s *s, int rv)
{
	if (s->flag == 2)
		mlx_destroy_window(s->g.mlx, s->g.win);
	s->g.win = NULL;
	free_mlx(s, rv);
	return (rv);
}

int		free_img(t_s *s, int rv)
{
	mlx_destroy_image(s->g.mlx, s->g.img.ptr);
	free_wind(s, rv);
	s->g.img.ptr = NULL;
	return (rv);
}

// int		free_img_xpm(t_s *s, int rv)
// {
// 	free_img(s, rv);
// 	free_xpm_SP(s, rv);
// 	return (rv);
// }
