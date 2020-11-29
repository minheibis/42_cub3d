#include "cub3d.h"

int		free_xpm_img(t_s *s, int rv)
{
	free_xpm_SP(s, rv);
	free_img(s, rv);
	return (rv);
}

int		free_exit(t_s *s, int rv)
{
	free_tex_map_sp(s, rv);
	free_xpm_img(s, rv);
	return (rv);
}
