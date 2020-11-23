#include "cub3d.h"

int		ft_save_check(char *arg, char *save)
{
	int		i;

	i = 0;
	while(arg[i] == save[i])
	{
		if(arg[i] == '\0' && save[i] == '\0')
			return (0);
		i++;
	}
	return (NOT_SAVE);
}

int		ft_cub_check(char *arg, char *cub)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	if (i > 4 && arg[i - 1] == cub[2] && arg[i - 2] == cub[1] && arg[i - 3] == cub[0] && arg[i - 4] == '.')
		return (0);
	else
		return (CUB_NAME_ERROR);
}
