#include "cub3d.h"

int		free_mlx(t_s *s, int rv)
{
	free_NULL(s->g.mlx);
	return (rv);
}

int		free_wind(t_s *s, int rv)
{
	mlx_destroy_window(s->g.mlx, s->g.win);
	free_mlx(s, rv);
	return (rv);
}

int		free_img(t_s *s, int rv)
{
	free_wind(s, rv);
	mlx_destroy_image(s->g.mlx, s->g.img.data);
	return (rv);
}
