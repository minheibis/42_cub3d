/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:09:08 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 12:09:09 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

/*
** w stands for inside the map(and it is same as '1' = wall)
** p stands for fake player(and it is same as '0')
** 2 changed to 'd' as space, 'y' as a wall
*/
int		ft_check_p_row(t_s *s, int i, int j)
{
	int	rv;

	/*
	**check i
	*/
	if ((rv = ft_check_cell(s, i, j)) != 0)
		return (rv);
	/*
	**check i-1
	*/
	if ((rv = ft_check_cell_around(s, i - 1, j)) != 0)
		return (rv);
	/*
	**check i+1
	*/
	if ((rv = ft_check_cell_around(s, i + 1, j)) != 0)
		return (rv);
	return (IS_MAP);
}

int		ft_check_p_col(t_s *s, int i, int j)
{
	int		rv;
	/*
	**check j
	*/
	if ((rv = ft_check_cell(s, i, j)) != 0)
		return (rv);
	/*
	**check j-1
	*/
	if ((rv = ft_check_cell_around(s, i, j - 1)) != 0)
		return (rv);
	/*
	**check j+1
	*/
	if ((rv = ft_check_cell_around(s, i, j + 1)) != 0)
		return (rv);
	return (IS_MAP);
}

int		ft_check_cell(t_s *s, int i, int j)
{
	if (ft_map_space(s->map.map[i][j]) == 1)
		s->map.map[i][j] = 'w';
	else if (ft_map_item(s, s->map.map[i][j]) == 1)
		s->map.map[i][j] = 'y';
	else if (s->map.map[i][j] == '1' || ft_map_fake_wall(s->map.map[i][j]) == 1)
		return (IS_WALL);
	else
		return (NO_WALL);
	return (0);
}

int		ft_check_cell_around(t_s *s, int i, int j)
{
	if (ft_map_space(s->map.map[i][j]) == 1)
	{
		s->map.map[i][j] = 'p';
		return (0);
	}
	else if (ft_map_item(s, s->map.map[i][j]) == 1)
	{
		s->map.map[i][j] = 'd';
		return (0);
	}
	else if (s->map.map[i][j] == '1' || ft_map_fake_wall(s->map.map[i][j]) == 1)
		return (0);
	return (NO_WALL);
}
