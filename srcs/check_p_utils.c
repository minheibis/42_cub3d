# include "cub3d.h"

int		ft_map_space(char c)
{
	if (c == '0'|| c == 'p')
		return (1);
	else
		return (0);
}

int		ft_map_item(char c)
{
	if (c == '2' || c == 'd')
		return (1);
	else
		return (0);
}

int		ft_map_player(char c)
{
	if (c == 'p' || c == 'd')
		return (1);
	else
		return (0);
}

int		ft_map_fake_wall(char c)
{
	if (c == 'w' || c == 'y')
		return (1);
	else
		return (0);
}
