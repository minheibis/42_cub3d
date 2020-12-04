#include "cub3d.h"

int		ft_error(int rv)
{
	if (rv == INPUT_NUM_ERROR)
		write(2, "Error\nInvalid number of arguments\n", 35);
	else if (rv == CUB_NAME_ERROR)
		write(2, "Error\nInvalid name of Cub file\n", 32);
	else if (rv == NOT_SAVE)
		write(2, "Error\nThird argument not --save\n", 33);
	else if (rv == MALLOC_ERROR_CUB_LIST_START)
		write(2, "Error\nmalloc error cub list start\n", 35);
	else if (rv == FILE_OPEN_ERROR)
		write(2, "Error\ncub file not opened\n", 27);
	else if (rv == GNL_ERROR)
		write(2, "Error\nline in cubfile not read well\n", 37);
	else if (rv == MALLOC_ERROR_TMP_CONTENT)
		write(2, "Error\nmalloc error for tmp content\n", 36);
	else if (rv == MALLOC_ERROR_NEXT_CUB_LIST)
		write(2, "Error\nmalloc error for next cub list\n", 38);
	else if (rv == SET_RESOL_ERROR)
		write(2, "Error\ncub file set resolution error\n", 37);
	else if (rv == NOT_ONE_ELEMENT_ERROR)
		write(2, "Error\ncub file has zero or more than one elemnt\n", 49);
	else if (rv == INVALID_LINE_ERROR)
		write(2, "Error\ncub file has invalid line\n", 33);
	else if (rv == MALLOC_ERROR_TEX_PATH)
		write(2, "Error\nmalloc error tex path\n", 29);
	else if (rv == SET_COLOR_ERROR)
		write(2, "Error\ncub file set color error\n", 32);
	else if (rv == NO_MAP_FOUND)
		write(2, "Error\nno map in cub file\n", 26);
	else if (rv == MALLOC_ERROR_MAP)
		write(2, "Error\nmalloc error map\n", 24);
	else if (rv == MALLOC_ERROR_MAP_XROW)
		write(2, "Error\nmalloc error map xrow\n", 24);
	else if (rv == MALLOC_ERROR_MAP_ROW)
		write(2, "Error\nmalloc error map row\n", 23);
	else if (rv == NOT_EMPTY_LINE_AFTER_MAP)
		write(2, "Error\nnot empty line after map in cub file\n", 44);
	else if (rv == NOT_SURROUNEDED_BY_WALLS)
		write(2, "Error\nplayer in map not surrounded by walls\n(or invalid letter inside map)\n", 76);
	else if (rv == NOT_ONE_PLAYER)
		write(2, "Error\nnot one player in the map\n", 33);
	else if (rv == FAIL_INIT)
		write(2, "Error\ncannot initialize for drawing\n", 37);
	else if (rv == XPM_FILE_ERROR)
		write(2, "Error\ncannot read xpm file\n", 28);
	else if (rv == MALLOC_ERROR_ZBUFF)
		write(2, "Error\nmalloc error for zbuffer\n", 32);
	else if (rv == MALLOC_ERROR_SP_X)
		write(2, "Error\nmalloc error for sp_x\n", 29);
	else if (rv == MALLOC_ERROR_SP_Y)
		write(2, "Error\nmalloc error for sp_y\n", 29);
	else if (rv == MALLOC_ERROR_SPORD)
		write(2, "Error\nmalloc error for spOrd\n", 30);
	else if (rv == MALLOC_ERROR_SPDIST)
		write(2, "Error\nmalloc error for spDist\n", 31);
	else if (rv == BMP_FILE_OPEN_ERROR)
		write(2, "Error\nbmp file does not open\n", 30);
	else if (rv == MALLOC_ERROR_BMP_LINE)
		write(2, "Error\nmalloc error for bmp line\n", 33);
	else if (rv == BMP_HEAD_WRITE_ERROR)
		write(2, "Error\nwrite error for bmp header\n", 34);
	else if (rv == BMP_RGB_WRITE_ERROR)
		write(2, "Error\nwrite error for bmp rgb\n", 31);
	return (0);
}
