/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:10:15 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 13:08:45 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_set_element(t_s *s)
{
	if (s->elem.f_r != 1)
		return (NOT_ONE_ELEMENT_ERROR);
	if (s->elem.f_no != 1)
		return (NOT_ONE_ELEMENT_ERROR);
	if (s->elem.f_so != 1)
		return (NOT_ONE_ELEMENT_ERROR);
	if (s->elem.f_we != 1)
		return (NOT_ONE_ELEMENT_ERROR);
	if (s->elem.f_ea != 1)
		return (NOT_ONE_ELEMENT_ERROR);
	if (s->elem.f_sp != 1)
		return (NOT_ONE_ELEMENT_ERROR);
	if (s->elem.f_f != 1)
		return (NOT_ONE_ELEMENT_ERROR);
	if (s->elem.f_c != 1)
		return (NOT_ONE_ELEMENT_ERROR);
	return (0);
}
