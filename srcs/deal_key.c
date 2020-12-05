/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:09:22 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 13:47:49 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_deal_key(int key_code, t_s *s)
{
	/*
	**exit
	*/
	if (key_code == KEY_ESC)
	{
		free_exit(s, 0);
		exit(0);
	}
	/*
	**move forward if no wall in front of you
	*/
	else if (key_code == KEY_W)
	{
		if (ft_map_in(s->map.map[(int)floor(s->g.p.posy)][(int)floor(s->g.p.posx + s->g.p.dirx * moveSpeed)]))
			s->g.p.posx += s->g.p.dirx * moveSpeed;
		if (ft_map_in(s->map.map[(int)floor(s->g.p.posy + s->g.p.diry * moveSpeed)][(int)floor(s->g.p.posx)]))
			s->g.p.posy += s->g.p.diry * moveSpeed;
	}
	/*
	**move backwards if no wall behind you
	*/
	else if (key_code == KEY_S)
	{
		if (ft_map_in(s->map.map[(int)floor(s->g.p.posy)][(int)floor(s->g.p.posx - s->g.p.dirx * moveSpeed)]))
			s->g.p.posx -= s->g.p.dirx * moveSpeed;
		if (ft_map_in(s->map.map[(int)floor(s->g.p.posy - s->g.p.diry * moveSpeed)][(int)floor(s->g.p.posx)]))
			s->g.p.posy -= s->g.p.diry * moveSpeed;
	}
	else
		return (ft_deal_key_AD(key_code, s));
	return (0);
}

int		ft_deal_key_AD(int key_code, t_s *s)
{
	/*
	**move right if no wall on left of you
	*/
	if (key_code == KEY_A)
	{
		if (ft_map_in(s->map.map[(int)floor(s->g.p.posy)][(int)floor(s->g.p.posx + s->g.p.diry * moveSpeed)]))
			s->g.p.posx += s->g.p.diry * moveSpeed;
		if (ft_map_in(s->map.map[(int)floor(s->g.p.posy - s->g.p.dirx * moveSpeed)][(int)floor(s->g.p.posx)]))
			s->g.p.posy -= s->g.p.dirx * moveSpeed;
	}
	/*
	**move left if no wall on right of you
	**is this true?? >> made it the way I think it is true
	*/
	else if (key_code == KEY_D)
	{
		if (ft_map_in(s->map.map[(int)floor(s->g.p.posy)][(int)floor(s->g.p.posx - s->g.p.diry * moveSpeed)]))
			s->g.p.posx -= s->g.p.diry * moveSpeed;
		if (ft_map_in(s->map.map[(int)floor(s->g.p.posy + s->g.p.dirx * moveSpeed)][(int)floor(s->g.p.posx)]))
			s->g.p.posy += s->g.p.dirx * moveSpeed;
	}
	else
		return (ft_deal_key_RL(key_code, s));
	return (0);
}

int		ft_deal_key_RL(int key_code, t_s *s)
{
	/*
	**rotate to the right
	*/
	if (key_code == KEY_AR_R)
	{
		/*
		**both camera direction and camera plane must be rotated
		*/
		s->g.p.olddirx = s->g.p.dirx;
		s->g.p.dirx = s->g.p.dirx * cos(rotSpeed) - s->g.p.diry * sin(rotSpeed);
		s->g.p.diry = s->g.p.olddirx * sin(rotSpeed) + s->g.p.diry * cos(rotSpeed);
		s->g.p.oldplanex = s->g.p.planeX;
		s->g.p.planeX = s->g.p.planeX * cos(rotSpeed) - s->g.p.planeY * sin(rotSpeed);
		s->g.p.planeY = s->g.p.oldplanex * sin(rotSpeed) + s->g.p.planeY * cos(rotSpeed);
	}
	/*
	**rotate to the left
	*/
	else if (key_code == KEY_AR_L)
	{
		/*
		**both camera direction and camera plane must be rotated
		*/
		s->g.p.olddirx = s->g.p.dirx;
		s->g.p.dirx = s->g.p.dirx * cos(-rotSpeed) - s->g.p.diry * sin(-rotSpeed);
		s->g.p.diry = s->g.p.olddirx * sin(-rotSpeed) + s->g.p.diry * cos(-rotSpeed);
		s->g.p.oldplanex = s->g.p.planeX;
		s->g.p.planeX = s->g.p.planeX * cos(-rotSpeed) - s->g.p.planeY * sin(-rotSpeed);
		s->g.p.planeY = s->g.p.oldplanex * sin(-rotSpeed) + s->g.p.planeY * cos(-rotSpeed);
	}
	return (0);
}
