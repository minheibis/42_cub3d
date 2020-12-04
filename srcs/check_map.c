#include "cub3d.h"

int		ft_check_map(t_s *s)
{
	int		flag_row;

	flag_row = 1;
	if (ft_find_player_fir(s) != 1)
		return (NOT_ONE_PLAYER);
	//delete after
	// printf("ft_check_map 1: s->map.map\n");
	// ft_show_map(s);
	while (ft_find_fake_player(s))
	{
		if (ft_edge_player(s))
			return (NOT_SURROUNEDED_BY_WALLS);
		else if (ft_find_wall(s, flag_row))
			return (NOT_SURROUNEDED_BY_WALLS);
		//delete after
		// printf("ft_check_map 2: s->map.map\n");
		// ft_show_map(s);
		flag_row *= -1;
	}
	ft_set_player_ag(s);
	// printf("ft_check_map 3: s->map.map\n");
	// ft_show_map(s);
	return (0);
}

int		ft_find_fake_player(t_s *s)
{
	t_ij	var;

	var.i = 1;
	while (var.i < s->map.map_hei + 1)
	{
		var.j = 1;
		while (var.j < s->map.map_wid + 1)
		{
			if (ft_map_player(s->map.map[var.i][var.j]) == 1)
			{
				/*
				**set the first (fake) player found here
				*/
				s->map.player[0] = var.i;
				s->map.player[1] = var.j;
				return (1);
			}
			var.j++;
		}
		var.i++;
	}
	return (0);
}

int		ft_find_wall(t_s *s, int flag_row)
{
	int		rv;

	if (flag_row == 1)
	{
		rv = ft_find_wall_row_for(s);
		if (rv == 0)
			rv = ft_find_wall_row_bac(s);
		if (rv == 0)
			return (0);
		else
			return (1);
	}
	else
	{
		rv = ft_find_wall_col_for(s);
		if (rv == 0)
			rv = ft_find_wall_col_bac(s);
		if (rv == 0)
			return (0);
		else
			return (1);
	}
}
