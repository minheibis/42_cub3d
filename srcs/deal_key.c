/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:09:22 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 15:43:51 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_deal_key(int key_code, t_s *s)
{
	if (key_code == KEY_ESC)
	{
		free_exit(s, 0);
		exit(0);
	}
	else if (key_code == KEY_W)
	{
		if (ft_map_in(s->map.map[(int)floor(s->g.p.posy)][(int)floor(s->g.p.posx + s->g.p.dirx * MOVESPEED)]))
			s->g.p.posx += s->g.p.dirx * MOVESPEED;
		if (ft_map_in(s->map.map[(int)floor(s->g.p.posy + s->g.p.diry * MOVESPEED)][(int)floor(s->g.p.posx)]))
			s->g.p.posy += s->g.p.diry * MOVESPEED;
	}
	else if (key_code == KEY_S)
	{
		if (ft_map_in(s->map.map[(int)floor(s->g.p.posy)][(int)floor(s->g.p.posx - s->g.p.dirx * MOVESPEED)]))
			s->g.p.posx -= s->g.p.dirx * MOVESPEED;
		if (ft_map_in(s->map.map[(int)floor(s->g.p.posy - s->g.p.diry * MOVESPEED)][(int)floor(s->g.p.posx)]))
			s->g.p.posy -= s->g.p.diry * MOVESPEED;
	}
	else
		return (ft_deal_key_ad(key_code, s));
	return (0);
}

int		ft_deal_key_ad(int key_code, t_s *s)
{
	if (key_code == KEY_A)
	{
		if (ft_map_in(s->map.map[(int)floor(s->g.p.posy)][(int)floor(s->g.p.posx + s->g.p.diry * MOVESPEED)]))
			s->g.p.posx += s->g.p.diry * MOVESPEED;
		if (ft_map_in(s->map.map[(int)floor(s->g.p.posy - s->g.p.dirx * MOVESPEED)][(int)floor(s->g.p.posx)]))
			s->g.p.posy -= s->g.p.dirx * MOVESPEED;
	}
	else if (key_code == KEY_D)
	{
		if (ft_map_in(s->map.map[(int)floor(s->g.p.posy)][(int)floor(s->g.p.posx - s->g.p.diry * MOVESPEED)]))
			s->g.p.posx -= s->g.p.diry * MOVESPEED;
		if (ft_map_in(s->map.map[(int)floor(s->g.p.posy + s->g.p.dirx * MOVESPEED)][(int)floor(s->g.p.posx)]))
			s->g.p.posy += s->g.p.dirx * MOVESPEED;
	}
	else
		return (ft_deal_key_rl(key_code, s));
	return (0);
}

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
	else if (key_code == KEY_AR_L)
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
