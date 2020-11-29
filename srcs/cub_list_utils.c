#include "cub3d.h"

int	ft_set_next_cub_list(t_s *s)
{
	t_cub_line *p_tmp_list;

	p_tmp_list = s->cub_list.tmp;
	if(!(s->cub_list.tmp->next = (t_cub_line *)malloc(sizeof(t_cub_line))))
		return (MALLOC_ERROR_NEXT_CUB_LIST);
	s->cub_list.tmp = s->cub_list.tmp->next;
	s->cub_list.tmp->content = NULL;
	s->cub_list.tmp->num = p_tmp_list->num + 1;
	s->cub_list.tmp->len = 0;
	s->cub_list.tmp->next = NULL;
	return (0);
}
