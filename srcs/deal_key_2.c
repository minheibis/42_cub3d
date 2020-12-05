/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:03:28 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 16:05:26 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_deal_key_rl(int key_code, t_s *s)
{
	if (key_code == KEY_AR_R)
	{
		s->g.p.olddirx = s->g.p.dirx;
		s->g.p.dirx = s->g.p.dirx * cos(ROTSPEED) -
			s->g.p.diry * sin(ROTSPEED);
		s->g.p.diry = s->g.p.olddirx * sin(ROTSPEED) +
			s->g.p.diry * cos(ROTSPEED);
		s->g.p.oldplanex = s->g.p.planex;
		s->g.p.planex = s->g.p.planex * cos(ROTSPEED) -
			s->g.p.planey * sin(ROTSPEED);
		s->g.p.planey = s->g.p.oldplanex * sin(ROTSPEED) +
			s->g.p.planey * cos(ROTSPEED);
	}
	else
		return (ft_deal_key_l(key_code, s));
	return (0);
}

int		ft_deal_key_l(int key_code, t_s *s)
{
	if (key_code == KEY_AR_L)
	{
		s->g.p.olddirx = s->g.p.dirx;
		s->g.p.dirx = s->g.p.dirx * cos(-ROTSPEED) -
			s->g.p.diry * sin(-ROTSPEED);
		s->g.p.diry = s->g.p.olddirx * sin(-ROTSPEED) +
			s->g.p.diry * cos(-ROTSPEED);
		s->g.p.oldplanex = s->g.p.planex;
		s->g.p.planex = s->g.p.planex * cos(-ROTSPEED) -
			s->g.p.planey * sin(-ROTSPEED);
		s->g.p.planey = s->g.p.oldplanex * sin(-ROTSPEED) +
			s->g.p.planey * cos(-ROTSPEED);
	}
	return (0);
}
