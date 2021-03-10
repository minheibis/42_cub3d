/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:10:35 by hyuki             #+#    #+#             */
/*   Updated: 2021/03/10 02:21:31 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_read_cub(t_s *s, char *cub_file)
{
	t_read_cub	r;

	r.line = NULL;
	if ((r.fd = open(cub_file, O_RDONLY)) == -1)
		return (FILE_OPEN_ERROR);
	r.rv = 1;
	s->cub_list.tmp = s->cub_list.start;
	while (r.rv == 1)
	{
		if ((r.rv = get_next_line(r.fd, &r.line)) == -1)
			return (GNL_ERROR);
		if (!(s->cub_list.tmp->content = ft_strdup(r.line)))
			return (free_return(r.line, MALLOC_ERROR_TMP_CONTENT));
		s->cub_list.tmp->len = ft_strlen(s->cub_list.tmp->content);
		if (r.rv == 1)
			if (ft_set_next_cub_list(s) != 0)
				return (free_return(r.line, MALLOC_ERROR_NEXT_CUB_LIST));
	}
	free_null(r.line);
	s->cub_list.tmp = s->cub_list.start;
	close(r.fd);
	if ((s->rv = ft_parse_cub(s)))
		return (s->rv);
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
