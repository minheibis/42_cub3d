#include "cub3d.h"

int		ft_error(int rv)
{
	if (rv == INPUT_NUM_ERROR)
		write(2, "Error\nInvalid number of arguments\n", 35);
	else if (rv == CUB_NAME_ERROR)
		write(2, "Error\nInvalid name of Cub file\n", 32);
	else if (rv == NOT_SAVE)
		write(2, "Error\nThird argument not --save\n", 33);
	else if (rv == FILE_OPEN_ERROR)
		write(2, "Error\ncub file not opened\n", 27);
	else if (rv == GNL_ERROR)
		write(2, "Error\nline in cubfile not read well\n", 37);
	else if (rv == MALLOC_ERROR)
		write(2, "Error\nmalloc error\n", 20);
	else if (rv == SET_COLOR_ERROR)
		write(2, "Error\ncub file color error\n", 28);
	else if (rv == NO_MAP_FOUND)
		write(2, "Error\nno map in cub file\n", 26);
	else if (rv == NOT_EMPTY_LINE_AFTER_MAP)
		write(2, "Error\nnot empty line after map in cub file\n", 44);
	else if (rv == NOT_SURROUNEDED_BY_WALLS)
		write(2, "Error\nplayer in map not surrounded by walls\n(or spacd inside map)\n", 67);
	else if (rv == NOT_ONE_PLAYER)
		write(2, "Error\nnot one player in the map\n", 33);
	else if (rv == FAIL_INIT)
		write(2, "Error\ncannot initialize for drawing\n", 37);
	else if (rv == XPM_FILE_ERROR)
		write(2, "Error\ncannot read xpm file\n", 28);
	return (0);
}
