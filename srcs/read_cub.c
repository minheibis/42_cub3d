#include "cub3d.h"

int		ft_read_cub(t_s *s, char *cub_file)
{
	int			fd;
	int			rv;
	char		*line;

	line = NULL;
	//printf("ft_read_cub: cub_file: [%s]\n", cub_file);
	if ((fd = open(cub_file, O_RDONLY)) == -1)
		return (FILE_OPEN_ERROR);
	rv = 1;
	//printf("cub_file: %s\n", cub_file);
	//printf("fd: %d\n", fd);
	s->cub_list.tmp = s->cub_list.start;
	while (rv == 1)
	{
		if ((rv = get_next_line(fd, &line)) == -1)
			return (GNL_ERROR);
		//printf("ft_read_cub: s->cub_list.tmp->num: [%d]\n", s->cub_list.tmp->num);
		if (!(s->cub_list.tmp->content = ft_strdup(line)))
			return (free_return(line, MALLOC_ERROR_TMP_CONTENT));
		s->cub_list.tmp->len = ft_strlen(s->cub_list.tmp->content);
		// printf("ft_read_cub: s->cub_list.tmp->content: [%s]\n", s->cub_list.tmp->content);
		if (rv == 1)
			if(ft_set_next_cub_list(s) != 0)
				return (free_return(line, MALLOC_ERROR_NEXT_CUB_LIST));
		// printf("ft_read_cub: s->cub_list.tmp->content: [%s]\n", s->cub_list.tmp->content);
		// printf("ft_read_cub: s->cub_list.tmp->next: [%p]\n", s->cub_list.tmp->next);
	}
	free_NULL(line);
	s->cub_list.tmp = s->cub_list.start;
	close(fd);
	if ((s->rv = ft_parse_cub(s)))
		return (free_tex(s, s->rv));
	return (0);
}

int		ft_parse_cub(t_s *s)
{
	if ((s->rv = ft_parse_element(s)))
		return (s->rv);
	if ((s->rv = ft_parse_map(s)))
		return (s->rv);
	if ((s->rv = ft_check_map(s)))
		return (free_map_all(s, s->rv));
	return (0);
}
