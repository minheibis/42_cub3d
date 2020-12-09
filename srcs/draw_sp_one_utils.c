/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sp_one_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 13:47:43 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/09 13:47:44 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_size_xy(int *check, int min, int max)
{
	if (*check < min)
		*check = min;
	if (*check > max - 1)
		*check = max - 1;
	return (0);
}
