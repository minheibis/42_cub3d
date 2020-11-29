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

int		main(void)
{
	//have to rewrite to argc, argv
	int		rv;
	int		argc;
	// char	argv_1[] = "test_fail.cub";
	// char	argv_1[] = "test_fail_2.cub";
	// char	argv_1[] = "test_fail_3.cub";
	// char	argv_1[] = "test.cub";
	char	argv_1[] = "test_2.cub";
	// char	argv_1[] = "test_3.cub";
	char	argv_2[] = "--save";

	//mtrace();
	argc = 2;
	rv = 0;
	if (argc == 2 || argc == 3)
	{
		if ((rv = ft_cub_check(argv_1, "cub")))
			return (ft_error(rv));
		if (argc == 3)
			if ((rv = ft_save_check(argv_2, "--save")))
				return (ft_error(rv));
		if ((rv = ft_parse_to_draw(argv_1, argc)))
			return (ft_error(rv));
	}
	else
		return(ft_error(INPUT_NUM_ERROR));
	//muntrace();
	return (0);
}
