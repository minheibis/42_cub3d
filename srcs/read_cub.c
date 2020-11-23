#include "cub3d.h"

int		ft_read_cub(t_s *s, char *cub_file)
{
	int			fd;
	int			rv;
	char		*line;

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
			return (MALLOC_ERROR);
		s->cub_list.tmp->len = ft_strlen(s->cub_list.tmp->content);
		// printf("ft_read_cub: s->cub_list.tmp->content: [%s]\n", s->cub_list.tmp->content);
		if (rv == 1)
			set_next_cub_list(s);
		// printf("ft_read_cub: s->cub_list.tmp->content: [%s]\n", s->cub_list.tmp->content);
		// printf("ft_read_cub: s->cub_list.tmp->next: [%p]\n", s->cub_list.tmp->next);
		free(line);
	}
	s->cub_list.tmp = s->cub_list.start;
	close(fd);
	if ((rv = ft_parse_cub(s)))
		return (rv);
	return (0);
}

int		ft_parse_cub(t_s *s)
{
	int	rv;

	rv = 0;
	if ((rv = ft_parse_element(s)))
		return (rv);
	if ((rv = ft_parse_map(s)))
		return (rv);
	if ((rv = ft_check_map(s)))
		return (rv);
	return (0);
}
