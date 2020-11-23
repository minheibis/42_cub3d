#include "cub3d.h"

int		free_return(char *s, int rv)
{
	free(s);
	s = NULL;
	return (rv);
}

int		set_fd(char **rest_fd, int fd)
{
	char	*buf;
	char	*tmp;
	int		read_val;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if ((read_val = read(fd, buf, BUFFER_SIZE)) < 0)
		return (free_return(buf, -1));
	buf[read_val] = '\0';
	tmp = *rest_fd;
	if (!((*rest_fd = ft_strjoin(*rest_fd, buf))))
		return (-1);
	free(tmp);
	free(buf);
	tmp = NULL;
	buf = NULL;
	return (read_val);
}

int		set_line(char **rest_fd, char **line)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while ((*rest_fd)[i] != '\n' && (*rest_fd)[i] != '\0')
		i++;
	if (!(*line = (char *)malloc(sizeof(char) * (i + 1))))
		return (-1);
	j = 0;
	while (j < i)
	{
		(*line)[j] = (*rest_fd)[j];
		j++;
	}
	(*line)[j] = '\0';
	if ((*rest_fd)[i] == '\n')
		i++;
	tmp = *rest_fd;
	if ((*rest_fd = ft_substr(*rest_fd, i, ft_strlen(*rest_fd))) == NULL)
		return (free_return(*line, -1));
	free(tmp);
	tmp = NULL;
	return ((i != j));
}

int		get_next_line(int fd, char **line)
{
	static char *rest[MAX_FD];
	int			read_val;

	if (fd < 0 || fd == 1 || fd == 2 || fd > MAX_FD
		|| line == NULL || BUFFER_SIZE < 1)
		return (-1);
	if (rest[fd] == NULL)
		rest[fd] = ft_strdup("");
	read_val = 1;
	while (ft_strchr(rest[fd], '\n') == NULL && read_val > 0)
		read_val = set_fd(&rest[fd], fd);
	if (read_val == -1)
		*line = NULL;
	else if (set_line(&rest[fd], line) == -1)
		*line = NULL;
	if (read_val == -1 || read_val == 0)
	{
		free(rest[fd]);
		rest[fd] = NULL;
	}
	else
		read_val = 1;
	return (read_val);
}
