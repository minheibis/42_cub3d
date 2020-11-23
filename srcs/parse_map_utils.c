#include "cub3d.h"

int		ft_parse_is_map_line(char *cub_line)
{
	int		i;

	i = 0;
	while (cub_line[i] != '\0' && (cub_line[i] == ' ' ||
	 cub_line[i] == '0' || cub_line[i] == '2'))
		i++;
	if (cub_line[i] != '\0' && cub_line[i] == '1')
		return (1);
	return (0);
}
