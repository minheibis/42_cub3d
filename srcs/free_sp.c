#include "cub3d.h"

int		free_sp_x(t_s *s, int rv)
{
	free_NULL(s->g.sp_i.sp_x);
	return (rv);
}

int		free_sp_y(t_s *s, int rv)
{
	free_sp_x(s, rv);
	free_NULL(s->g.sp_i.sp_y);
	return (rv);
}

int		free_spOrd(t_s *s, int rv)
{
	free_sp_y(s, rv);
	free_NULL(s->g.sp_i.spOrd);
	return (rv);
}

int		free_sp_all(t_s *s, int rv)
{
	free_spOrd(s, rv);
	free_NULL(s->g.sp_i.spDist);
	return (rv);
}

int		free_tex_map_sp(t_s *s, int rv)
{
	free_tex_map(s, rv);
	free_sp_all(s, rv);
	return (rv);
}
