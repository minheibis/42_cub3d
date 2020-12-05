/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:09:46 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 13:53:58 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		free_sp_zbuff(t_s *s, int rv)
{
	free_NULL(s->g.sp_i.zbuff);
	return (rv);
}

int		free_sp_x(t_s *s, int rv)
{
	free_sp_zbuff(s, rv);
	free_NULL(s->g.sp_i.sp_x);
	return (rv);
}

int		free_sp_y(t_s *s, int rv)
{
	free_sp_x(s, rv);
	free_NULL(s->g.sp_i.sp_y);
	return (rv);
}

int		free_spord(t_s *s, int rv)
{
	free_sp_y(s, rv);
	free_NULL(s->g.sp_i.spord);
	return (rv);
}

int		free_sp_all(t_s *s, int rv)
{
	free_spord(s, rv);
	free_NULL(s->g.sp_i.spdist);
	return (rv);
}
