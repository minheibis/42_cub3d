# include "cub3d.h"

/*
** w stands for inside the map(and it is same as '1' = wall)
** p stands for fake player(and it is same as '0')
** 2 changed to 'd' as space, 'y' as a wall
*/
int		ft_check_p_row(t_s *s, int i, int j)
{
	if (ft_map_space(s->map.map[i][j]) == 1 || ft_map_item(s->map.map[i][j]) == 1)
	{
		if (ft_map_item(s->map.map[i][j]) == 1)
			s->map.map[i][j] = 'y';
		else
			s->map.map[i][j] = 'w';
		if (ft_map_space(s->map.map[i - 1][j]) == 1)
			s->map.map[i - 1][j] = 'p';
		else if (ft_map_item(s->map.map[i - 1][j]) == 1)
			s->map.map[i - 1][j] = 'd';
		if (ft_map_space(s->map.map[i + 1][j]) == 1)
			s->map.map[i + 1][j] = 'p';
		else if (ft_map_item(s->map.map[i + 1][j]) == 1)
			s->map.map[i + 1][j] = 'd';
		return (IS_MAP);
	}
	else if (s->map.map[i][j] == '1' || ft_map_fake_wall(s->map.map[i][j]) == 1)
		return (IS_WALL);
	else
		return (NO_WALL);
}

int		ft_check_p_col(t_s *s, int i, int j)
{
	if (ft_map_space(s->map.map[i][j]) == 1 || ft_map_item(s->map.map[i][j]) == 1)
	{
		if (ft_map_item(s->map.map[i][j]) == 1)
			s->map.map[i][j] = 'y';
		else
			s->map.map[i][j] = 'w';
		if (ft_map_space(s->map.map[i][j - 1]) == 1)
			s->map.map[i][j - 1] = 'p';
		else if (ft_map_item(s->map.map[i][j - 1]) == 1)
			s->map.map[i][j - 1] = 'd';
		if (ft_map_space(s->map.map[i][j + 1]) == 1)
			s->map.map[i][j + 1] = 'p';
		else if (ft_map_item(s->map.map[i][j + 1]) == 1)
			s->map.map[i][j + 1] = 'd';
		return (IS_MAP);
	}
	else if (s->map.map[i][j] == '1' || ft_map_fake_wall(s->map.map[i][j]) == 1)
		return (IS_WALL);
	else
		return (NO_WALL);
}
