/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:09:46 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 12:09:48 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		free_sp_Zbuff(t_s *s, int rv)
{
	free_NULL(s->g.sp_i.ZBuff);
	return (rv);
}

int		free_sp_x(t_s *s, int rv)
{
	free_sp_Zbuff(s, rv);
	free_NULL(s->g.sp_i.sp_x);
	return (rv);
}

int		free_sp_y(t_s *s, int rv)
{
	free_sp_x(s, rv);
	free_NULL(s->g.sp_i.sp_y);
	return (rv);
}

int		free_spOrd(t_s *s, int rv)
{
	free_sp_y(s, rv);
	free_NULL(s->g.sp_i.spOrd);
	return (rv);
}

int		free_sp_all(t_s *s, int rv)
{
	free_spOrd(s, rv);
	free_NULL(s->g.sp_i.spDist);
	return (rv);
}
