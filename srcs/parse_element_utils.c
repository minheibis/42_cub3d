/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:10:15 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 12:10:16 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_set_element(t_s *s)
{
	if (s->elem.f_R != 1)
		return (NOT_ONE_ELEMENT_ERROR);
	if (s->elem.f_NO != 1)
		return (NOT_ONE_ELEMENT_ERROR);
	if (s->elem.f_SO != 1)
		return (NOT_ONE_ELEMENT_ERROR);
	if (s->elem.f_WE != 1)
		return (NOT_ONE_ELEMENT_ERROR);
	if (s->elem.f_EA != 1)
		return (NOT_ONE_ELEMENT_ERROR);
	if (s->elem.f_SP != 1)
		return (NOT_ONE_ELEMENT_ERROR);
	if (s->elem.f_F != 1)
		return (NOT_ONE_ELEMENT_ERROR);
	if (s->elem.f_C != 1)
		return (NOT_ONE_ELEMENT_ERROR);
	return (0);
}
