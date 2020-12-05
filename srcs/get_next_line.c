/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 10:33:43 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 14:13:44 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		set_rest(char **rest, int fd)
{
	char	*buf;
	char	*tmp;
	int		rv;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if ((rv = read(fd, buf, BUFFER_SIZE)) == -1)
		return (free_return(buf, -1));
	buf[rv] = 0;
	/*
	**keep tmp for free of old rest
	*/
	tmp = *rest;
	if (!(*rest = ft_strjoin(*rest, buf)))
		return (free_return(tmp, free_return(buf, -1)));
	free_null(tmp);
	free_null(buf);
	return (rv);
}


int		set_line(char **rest, char **line)
{
	int		rv;
	int		i;
	char	*tmp;

	i = 0;
	rv = 0;
	while ((*rest)[i] != '\n' && (*rest)[i] != '\0')
		i++;
	tmp = *line;
	if (!(*line = ft_substr(*rest, 0, i)))
		return (free_return(tmp, free_return(rest, -1)));
	free_null(tmp);
	if ((*rest)[i] == '\n')
	{
		i++;
		rv = 1;
	}
	/*
	**keep tmp for free of old rest
	*/
	tmp = *rest;
	if (!(*rest = ft_substr(*rest, i, ft_strlen(*rest))))
		return (free_return(*line, free_return(tmp, -1)));
	free_null(tmp);
	return (rv);
}

int		get_next_line(int fd, char **line)
{
	static char *rest;
	int			rv;

	if (fd < 0 || fd == 1 || fd == 2 || fd > MAX_FD
		|| line == NULL || BUFFER_SIZE < 1)
		return (-1);
	if (rest == NULL)
	{
		if (!(rest = ft_strdup("")))
			return (-1);
	}
	rv = 1;
	/*
	**strchr is what we need here. rv>0 is for error handling.
	*/
	while (ft_strchr(rest, '\n') == NULL && rv > 0)
	{
		if ((rv = set_rest(&rest, fd)) == -1)
			free_return(*line, -1);
	}
	rv = set_line(&rest, line);
	if (rv == 0)
		free_null(rest);
	return (rv);
}
