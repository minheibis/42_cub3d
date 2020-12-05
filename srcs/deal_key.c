/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:09:22 by hyuki             #+#    #+#             */
/*   Updated: 2020/12/05 12:14:45 by hyuki            ###   ########.fr       */
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
		if (ft_map_in(s->map.map[(int)floor(s->g.p.posY)][(int)floor(s->g.p.posX + s->g.p.dirX * moveSpeed)]))
			s->g.p.posX += s->g.p.dirX * moveSpeed;
		if (ft_map_in(s->map.map[(int)floor(s->g.p.posY + s->g.p.dirY * moveSpeed)][(int)floor(s->g.p.posX)]))
			s->g.p.posY += s->g.p.dirY * moveSpeed;
	}
	/*
	**move backwards if no wall behind you
	*/
	else if (key_code == KEY_S)
	{
		if (ft_map_in(s->map.map[(int)floor(s->g.p.posY)][(int)floor(s->g.p.posX - s->g.p.dirX * moveSpeed)]))
			s->g.p.posX -= s->g.p.dirX * moveSpeed;
		if (ft_map_in(s->map.map[(int)floor(s->g.p.posY - s->g.p.dirY * moveSpeed)][(int)floor(s->g.p.posX)]))
			s->g.p.posY -= s->g.p.dirY * moveSpeed;
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
		if (ft_map_in(s->map.map[(int)floor(s->g.p.posY)][(int)floor(s->g.p.posX + s->g.p.dirY * moveSpeed)]))
			s->g.p.posX += s->g.p.dirY * moveSpeed;
		if (ft_map_in(s->map.map[(int)floor(s->g.p.posY - s->g.p.dirX * moveSpeed)][(int)floor(s->g.p.posX)]))
			s->g.p.posY -= s->g.p.dirX * moveSpeed;
	}
	/*
	**move left if no wall on right of you
	**is this true?? >> made it the way I think it is true
	*/
	else if (key_code == KEY_D)
	{
		if (ft_map_in(s->map.map[(int)floor(s->g.p.posY)][(int)floor(s->g.p.posX - s->g.p.dirY * moveSpeed)]))
			s->g.p.posX -= s->g.p.dirY * moveSpeed;
		if (ft_map_in(s->map.map[(int)floor(s->g.p.posY + s->g.p.dirX * moveSpeed)][(int)floor(s->g.p.posX)]))
			s->g.p.posY += s->g.p.dirX * moveSpeed;
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
		s->g.p.oldDirX = s->g.p.dirX;
		s->g.p.dirX = s->g.p.dirX * cos(rotSpeed) - s->g.p.dirY * sin(rotSpeed);
		s->g.p.dirY = s->g.p.oldDirX * sin(rotSpeed) + s->g.p.dirY * cos(rotSpeed);
		s->g.p.oldPlaneX = s->g.p.planeX;
		s->g.p.planeX = s->g.p.planeX * cos(rotSpeed) - s->g.p.planeY * sin(rotSpeed);
		s->g.p.planeY = s->g.p.oldPlaneX * sin(rotSpeed) + s->g.p.planeY * cos(rotSpeed);
	}
	/*
	**rotate to the left
	*/
	else if (key_code == KEY_AR_L)
	{
		/*
		**both camera direction and camera plane must be rotated
		*/
		s->g.p.oldDirX = s->g.p.dirX;
		s->g.p.dirX = s->g.p.dirX * cos(-rotSpeed) - s->g.p.dirY * sin(-rotSpeed);
		s->g.p.dirY = s->g.p.oldDirX * sin(-rotSpeed) + s->g.p.dirY * cos(-rotSpeed);
		s->g.p.oldPlaneX = s->g.p.planeX;
		s->g.p.planeX = s->g.p.planeX * cos(-rotSpeed) - s->g.p.planeY * sin(-rotSpeed);
		s->g.p.planeY = s->g.p.oldPlaneX * sin(-rotSpeed) + s->g.p.planeY * cos(-rotSpeed);
	}
	return (0);
}
