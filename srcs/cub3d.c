#include "cub3d.h"

int		ft_parse_to_draw(char *cub_file, int flag)
{
	t_s s;

	s.rv = 0;
	s.flag = flag;
	ft_init_s(&s);
	//free each unique malloc in each function, (map etc is exception)
	if ((s.rv = ft_read_cub(&s, cub_file)))
		return (free_cublist(&s));
	if ((s.rv = ft_draw_map(&s)))
		return (free_tex_map(&s, s.rv));
	free_cublist(&s);
	return (0);
}

int		main(int argc, char **argv)
{
	//int argc, char **argv
	//have to rewrite to argc, argv
	int		rv;
	// int		argc;
	// char	argv_1[] = "test_fail_1_open_map.cub";
	// char	argv_1[] = "test_fail_2_space_in_map.cub";
	// char	argv_1[] = "test_fail_3_invalid_num.cub";
	// char	argv_1[] = "test_fail_4_two_players.cub";
	// char	argv_1[] = "test_fail_5_three_players.cub";
	// // char	argv_1[] = "test_fail_3.cub";
	// // char	argv_1[] = "test.cub";
	// char	argv_1[] = "test_2.cub";
	// char	argv_1[] = "test_3.cub";
	// char	argv_1[] = "test_4_map_shape_plus.cub";
	// char	argv_1[] = "test_6_large_map_4000.cub";
	// char	argv_1[] = "test_7_large_map_125000.cub";
	// char	argv_2[] = "--save";

	//mtrace();
	// argc = 2;
	rv = 0;
	if (argc == 2 || argc == 3)
	{
		if ((rv = ft_cub_check(argv[1], "cub")))
			return (ft_error(rv));
		if (argc == 3)
			if ((rv = ft_save_check(argv[2], "--save")))
				return (ft_error(rv));
		if ((rv = ft_parse_to_draw(argv[1], argc)))
			return (ft_error(rv));
	}
	else
		return(ft_error(INPUT_NUM_ERROR));
	//muntrace();
	return (0);
}
