/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:10:22 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/09 10:29:14 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_parse_is_map_line(char *cub_line)
{
	int		i;

	i = 0;
	if (cub_line[i] == '\0')
		return (0);
	while (ft_parse_is_map_letter(cub_line[i]))
	{
		i++;
	}
	if (cub_line[i] == '\0')
		return (1);
	return (0);
}

int		ft_parse_is_map_letter(char c)
{
	if (c == '0' || c == ' ' || c == '1' || c == '2')
		return (1);
	else if (ft_is_nsew(c))
		return (1);
	return (0);
}
