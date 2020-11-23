#include "cub3d.h"

int		ft_parse_element(t_s *s)
{
	/*
	**Except for the map content,
	**	 each type of element can be separated by one or more empty line(s).
	**Except for the map content which always has to be the last,
	**	 each type of element can be set in any order in the file.
	**Except for the map, each type of information from
	**	 an element can be separated by one or more space(s).
	*/
	int		rv;

	while (s->cub_list.tmp->next)
	{
		// printf("ft_parse_element: s->cub_list.tmp->content [%s]\n", s->cub_list.tmp->content);
		// printf("ft_parse_element: s->cub_list.tmp->num [%d]\n", s->cub_list.tmp->num);
		if (s->cub_list.tmp->content[0] == 'R' && s->cub_list.tmp->content[1] == ' ')
			rv = ft_parse_R(s);
		else if (s->cub_list.tmp->content[0] == 'N' && s->cub_list.tmp->content[1] == 'O' && s->cub_list.tmp->content[2] == ' ')
			rv = ft_parse_tex(s, &(s->map.nor_tex_path));
		else if (s->cub_list.tmp->content[0] == 'S' && s->cub_list.tmp->content[1] == 'O' && s->cub_list.tmp->content[2] == ' ')
			rv = ft_parse_tex(s, &(s->map.sou_tex_path));
		else if (s->cub_list.tmp->content[0] == 'W' && s->cub_list.tmp->content[1] == 'E' && s->cub_list.tmp->content[2] == ' ')
			rv = ft_parse_tex(s, &(s->map.wes_tex_path));
		else if (s->cub_list.tmp->content[0] == 'E' && s->cub_list.tmp->content[1] == 'A' && s->cub_list.tmp->content[2] == ' ')
			rv = ft_parse_tex(s, &(s->map.eas_tex_path));
		else if (s->cub_list.tmp->content[0] == 'S' && s->cub_list.tmp->content[1] == ' ')
			rv = ft_parse_tex(s, &(s->map.spr_tex_path));
		else if (s->cub_list.tmp->content[0] == 'F' && s->cub_list.tmp->content[1] == ' ')
			rv = ft_parse_color(s, &(s->map.flo_color[0]));
		else if (s->cub_list.tmp->content[0] == 'C' && s->cub_list.tmp->content[1] == ' ')
			rv = ft_parse_color(s, &(s->map.cel_color[0]));
		// printf("ft_parse_element: s->map.wid_resol [%d]\n", s->map.wid_resol);
		// printf("ft_parse_element: s->map.hei_resol [%d]\n", s->map.hei_resol);
		// printf("ft_parse_element: s->map.nor_tex_path [%s]\n", s->map.nor_tex_path);
		// printf("ft_parse_element: s->map.sou_tex_path [%s]\n", s->map.sou_tex_path);
		// printf("ft_parse_element: s->map.wes_tex_path [%s]\n", s->map.wes_tex_path);
		// printf("ft_parse_element: s->map.eas_tex_path [%s]\n", s->map.eas_tex_path);
		// printf("ft_parse_element: s->map.spr_tex_path [%s]\n", s->map.spr_tex_path);
		// printf("ft_parse_element: s->map.cel_color[0] [%d]\n", s->map.cel_color[0]);
		// printf("ft_parse_element: s->map.cel_color[1] [%d]\n", s->map.cel_color[1]);
		// printf("ft_parse_element: s->map.cel_color[2] [%d]\n", s->map.cel_color[2]);
		// printf("ft_parse_element: s->map.flo_color[0] [%d]\n", s->map.flo_color[0]);
		// printf("ft_parse_element: s->map.flo_color[1] [%d]\n", s->map.flo_color[1]);
		// printf("ft_parse_element: s->map.flo_color[2] [%d]\n", s->map.flo_color[2]);
		if (rv != 0)
			return (rv);
		s->cub_list.tmp = s->cub_list.tmp->next;
	}
	return (0);
}

int		ft_parse_R(t_s *s)
{
	int		i;

	i = 0;
	while(s->cub_list.tmp->content[i] != ' ')
		i++;
	while(s->cub_list.tmp->content[i] == ' ')
		i++;
	while (ft_isnum(s->cub_list.tmp->content[i]))
	{
		s->map.wid_resol *= 10;
		s->map.wid_resol += (s->cub_list.tmp->content[i] - '0');
		i++;
	}
	while(s->cub_list.tmp->content[i] == ' ')
		i++;
	while (ft_isnum(s->cub_list.tmp->content[i]))
	{
		s->map.hei_resol *= 10;
		s->map.hei_resol += (s->cub_list.tmp->content[i] - '0');
		i++;
	}
	if (s->cub_list.tmp->content[i] != '\0')
		return (SET_COLOR_ERROR);
	return (0);
}

int		ft_parse_tex(t_s *s, char **p_tex_path)
{
	int		i;

	i = 0;
	while(s->cub_list.tmp->content[i] != ' ')
		i++;
	while(s->cub_list.tmp->content[i] == ' ')
		i++;
	if(!(*p_tex_path = ft_strdup(s->cub_list.tmp->content + i)))
		return (MALLOC_ERROR);
	return (0);
}

int		ft_parse_color(t_s *s, int *p_color_path)
{
	int		i;
	int		j;

	i = 0;
	while(s->cub_list.tmp->content[i] != ' ')
		i++;
	j = 0;
	while (j < 3)
	{
		if (j == 0)
			while (s->cub_list.tmp->content[i] == ' ')
				i++;
		else if (s->cub_list.tmp->content[i] == ',')
			i++;
		while (ft_isnum(s->cub_list.tmp->content[i]))
		{
			p_color_path[j] *= 10;
			p_color_path[j] += (s->cub_list.tmp->content[i] - '0');
			if (p_color_path[j] > 255)
				return (SET_COLOR_ERROR);
			i++;
		}
		j++;
	}
	if (s->cub_list.tmp->content[i] != '\0')
		return (SET_COLOR_ERROR);
	return (0);
}
