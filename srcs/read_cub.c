/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:10:35 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 12:23:09 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_read_cub(t_s *s, char *cub_file)
{
	int			fd;
	int			rv;
	char		*line;

	line = NULL;
	if ((fd = open(cub_file, O_RDONLY)) == -1)
		return (FILE_OPEN_ERROR);
	rv = 1;
	s->cub_list.tmp = s->cub_list.start;
	while (rv == 1)
	{
		if ((rv = get_next_line(fd, &line)) == -1)
			return (GNL_ERROR);
		if (!(s->cub_list.tmp->content = ft_strdup(line)))
			return (free_return(line, MALLOC_ERROR_TMP_CONTENT));
		s->cub_list.tmp->len = ft_strlen(s->cub_list.tmp->content);
		if (rv == 1)
			if(ft_set_next_cub_list(s) != 0)
				return (free_return(line, MALLOC_ERROR_NEXT_CUB_LIST));
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
