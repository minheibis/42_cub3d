/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:09:22 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 16:38:36 by hyuki            ###   ########.fr       */
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
		if (ft_map_in(s->map.map
			[(int)floor(s->g.p.posy)]
			[(int)floor(s->g.p.posx + s->g.p.dirx * SPEED)]))
			s->g.p.posx += s->g.p.dirx * SPEED;
		if (ft_map_in(s->map.map
			[(int)floor(s->g.p.posy + s->g.p.diry * SPEED)]
			[(int)floor(s->g.p.posx)]))
			s->g.p.posy += s->g.p.diry * SPEED;
	}
	else
		return (ft_deal_key_s(key_code, s));
	return (0);
}

int		ft_deal_key_s(int key_code, t_s *s)
{
	if (key_code == KEY_S)
	{
		if (ft_map_in(s->map.map
			[(int)floor(s->g.p.posy)]
			[(int)floor(s->g.p.posx - s->g.p.dirx * SPEED)]))
			s->g.p.posx -= s->g.p.dirx * SPEED;
		if (ft_map_in(s->map.map
			[(int)floor(s->g.p.posy - s->g.p.diry * SPEED)]
			[(int)floor(s->g.p.posx)]))
			s->g.p.posy -= s->g.p.diry * SPEED;
	}
	else
		return (ft_deal_key_ad(key_code, s));
	return (0);
}

int		ft_deal_key_ad(int key_code, t_s *s)
{
	if (key_code == KEY_A)
	{
		if (ft_map_in(s->map.map
			[(int)floor(s->g.p.posy)]
			[(int)floor(s->g.p.posx + s->g.p.diry * SPEED)]))
			s->g.p.posx += s->g.p.diry * SPEED;
		if (ft_map_in(s->map.map
			[(int)floor(s->g.p.posy - s->g.p.dirx * SPEED)]
			[(int)floor(s->g.p.posx)]))
			s->g.p.posy -= s->g.p.dirx * SPEED;
	}
	else if (key_code == KEY_D)
	{
		if (ft_map_in(s->map.map
			[(int)floor(s->g.p.posy)]
			[(int)floor(s->g.p.posx - s->g.p.diry * SPEED)]))
			s->g.p.posx -= s->g.p.diry * SPEED;
		if (ft_map_in(s->map.map
			[(int)floor(s->g.p.posy + s->g.p.dirx * SPEED)]
			[(int)floor(s->g.p.posx)]))
			s->g.p.posy += s->g.p.dirx * SPEED;
	}
	else
		return (ft_deal_key_rl(key_code, s));
	return (0);
}
