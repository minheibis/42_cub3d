# include "cub3d.h"

int		free_cublist(t_s *s)
{
	t_cub_line *tmp_list;

	while (s->cub_list.start->next)
	{
		tmp_list = s->cub_list.start->next;
		free_NULL(s->cub_list.start->content);
		free_NULL(s->cub_list.start);
		s->cub_list.start = tmp_list;
	}
	free_NULL(s->cub_list.start->content);
	free_NULL(s->cub_list.start);
	return (s->rv);
}

int		free_tex(t_s *s, int rv)
{
	if (s->elem.f_NO > 0)
		free_NULL(s->map.nor_tex_path);
	if (s->elem.f_SP > 0)
		free_NULL(s->map.sou_tex_path);
	if (s->elem.f_EA > 0)
		free_NULL(s->map.eas_tex_path);
	if (s->elem.f_WE > 0)
		free_NULL(s->map.wes_tex_path);
	if (s->elem.f_SP > 0)
		free_NULL(s->map.spr_tex_path);
	return (rv);
}
