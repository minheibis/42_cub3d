#include "cub3d.h"

int		ft_draw_sp_one(t_s *s, int i)
{
	ft_draw_sp_one_pos(s, i);

	int	y;


	/*
	**calculate height of the sprite on screen
	*/
	s->g.sp_i.spH = abs((int)floor(s->g.img.scre_height / s->g.sp_i.trY));
	s->g.sp_i.drawSY = -s->g.sp_i.spH / 2 + s->g.img.scre_height / 2;
	if (s->g.sp_i.drawSY < 0)
		s->g.sp_i.drawSY = 0;
	s->g.sp_i.drawEY = s->g.sp_i.spH / 2 + s->g.img.scre_height / 2;
	if (s->g.sp_i.drawEY >= s->g.img.scre_height)
		s->g.sp_i.drawEY = s->g.img.scre_height - 1;
	/*
	**calculate width of the sprite on screen
	*/
	s->g.sp_i.spW = abs((int)floor(s->g.img.scre_width / s->g.sp_i.trX)); //same as the sprite height??
	s->g.sp_i.drawSX = -s->g.sp_i.spW / 2 + s->g.sp_i.spScX;
	if (s->g.sp_i.drawSX < 0)
		s->g.sp_i.drawSX = 0;
	s->g.sp_i.drawEX = s->g.sp_i.spW / 2 + s->g.sp_i.spScX;
	if (s->g.sp_i.drawEX >= s->g.img.scre_width)
		s->g.sp_i.drawEX = s->g.img.scre_width - 1;
	/*
	**loop through every vertical stripe of the sprite on screen
	*/
	s->g.sp_i.stripe = s->g.sp_i.drawSX;
	while (s->g.sp_i.stripe < s->g.sp_i.drawEX)
	{
		s->g.d_c.texX = (int)floor(256 * (s->g.sp_i.stripe - (-s->g.sp_i.spW / 2 + s->g.sp_i.spScX)) * s->g.ws.sp.width / s->g.sp_i.spW) / 256;
		/*
		**the conditions in the if are
		**1) it is in front of camera plane so you don't see things behind you
		**2) it is on the screen (left side)
		**3) it is on the screen (right side)
		**4)Zbuffer, with perpendicular distance
		**/
		if (s->g.sp_i.trY > 0 && s->g.sp_i.stripe > 0 && s->g.sp_i.stripe < s->g.img.scre_width && s->g.sp_i.trY < s->g.sp_i.ZBuff[s->g.sp_i.stripe])
		{
			/*
			**for every pixel for the current stripe
			*/
			y = s->g.sp_i.drawSY;
			while (y < s->g.sp_i.drawEY)
			{
				s->g.sp_i.d = (y) * 256 - s->g.img.scre_height * 128 + s->g.sp_i.spH * 128;
				s->g.d_c.texY = ((s->g.sp_i.d * s->g.ws.sp.height) / s->g.sp_i.spH) / 256;
				s->g.d_c.color = s->g.ws.sp.data[s->g.ws.sp.height * s->g.d_c.texY + s->g.d_c.texX];
				//printf("s->g.d_c.color [%d]\n", s->g.d_c.color);
				if (s->g.d_c.color != 0x000000)
					s->g.img.data[to_coord(s->g.sp_i.stripe, y, s)] = s->g.d_c.color;
				y++;
			}
		}
		s->g.sp_i.stripe++;
	}
	return (0);
}

int		ft_draw_sp_one_pos(t_s *s, int i);
{
	/*
	**translate sprite position to relative to camera
	*/
	s->g.sp_i.spX = s->g.sp_i.sp_x[s->g.sp_i.spOrd[i]] - s->g.p.posX;
	s->g.sp_i.spY = s->g.sp_i.sp_y[s->g.sp_i.spOrd[i]] - s->g.p.posY;
	/*
	**transform sprite with inverse camera matrix
	*/
	s->g.sp_i.invDet = 1.0 / (s->g.p.planeX * s->g.p.dirY - s->g.p.dirX * s->g.p.planeY);
	s->g.sp_i.trX = s->g.sp_i.invDet * (s->g.p.dirY * s->g.sp_i.spX - s->g.p.dirX * s->g.sp_i.spY);
	s->g.sp_i.trY = s->g.sp_i.invDet * (-s->g.p.planeY * s->g.sp_i.spX + s->g.p.planeX * s->g.sp_i.spY);
	/*
	**this is actually the depth inside the screen, that what Z is in 3D
	*/
	s->g.sp_i.spScX = (int)floor((s->g.img.scre_width / 2) * (1 + s->g.sp_i.trX / s->g.sp_i.trY));
}
