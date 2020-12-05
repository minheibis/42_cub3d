/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:09:17 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 12:14:10 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_parse_to_draw(char *cub_file, int flag)
{
	t_s s;

	s.rv = 0;
	s.flag = flag;
	ft_init_s(&s);
	if ((s.rv = ft_read_cub(&s, cub_file)))
		return (free_cublist(&s));
	if ((s.rv = ft_draw_map(&s)))
		return (free_tex_map(&s, s.rv));
	free_cublist(&s);
	return (0);
}

int		main(int argc, char **argv)
{
	int		rv;

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
	return (0);
}
