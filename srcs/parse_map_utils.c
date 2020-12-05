/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:10:22 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 16:14:03 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
