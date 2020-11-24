#include "cub3d.h"

int		ft_draw_sp_one(t_s *s, int i)
{
	ft_draw_sp_one_pos(s, i);
	ft_draw_sp_one_HW(s);
	ft_draw_sp_one_draw(s);
	return (0);
}

int		ft_draw_sp_one_pos(t_s *s, int i)
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
	** is this true?
	*/
	s->g.sp_i.spScX = (int)floor(s->g.img.scre_width * (0.5 - s->g.sp_i.trX / (s->g.sp_i.trY * 0.66 * 2)));
 	return (0);
}

int		ft_draw_sp_one_HW(t_s *s)
{
	/*
	**calculate height of the sprite on screen
	** same as using prepwalldist
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
	** same as the spH for drawing a square sprite
	*/
	s->g.sp_i.spW = s->g.sp_i.spH;
	s->g.sp_i.drawSX = -s->g.sp_i.spW / 2 + s->g.sp_i.spScX;
	if (s->g.sp_i.drawSX < 0)
		s->g.sp_i.drawSX = 0;
	s->g.sp_i.drawEX = s->g.sp_i.spW / 2 + s->g.sp_i.spScX;
	if (s->g.sp_i.drawEX >= s->g.img.scre_width)
		s->g.sp_i.drawEX = s->g.img.scre_width - 1;
	return (0);
}

int		ft_draw_sp_one_draw(t_s *s)
{
	int	y;
	/*
	**loop through every vertical stripe of the sprite on screen
	*/
	s->g.sp_i.stripe = s->g.sp_i.drawSX;
	while (s->g.sp_i.stripe < s->g.sp_i.drawEX)
	{
		s->g.d_c.texX = (int)floor(((double)s->g.sp_i.stripe - ((double)s->g.sp_i.spScX -(double)s->g.sp_i.spW / 2)) * (double)s->g.ws.sp.width / (double)s->g.sp_i.spW);
		/*
		**the conditions in the if are
		**1) it is in front of camera plane so you don't see things behind you: s->g.sp_i.trY > 0
		**2) it is on the screen (left side): s->g.sp_i.stripe > 0
		**3) it is on the screen (right side): s->g.sp_i.stripe < s->g.img.scre_width
		**4) it is in front of the wall: s->g.sp_i.trY < s->g.sp_i.ZBuff[s->g.sp_i.stripe]
		**/
		if (s->g.sp_i.trY > 0 && s->g.sp_i.stripe > 0 && s->g.sp_i.stripe < s->g.img.scre_width && s->g.sp_i.trY < s->g.sp_i.ZBuff[s->g.sp_i.stripe])
		{
			/*
			**for every pixel for the current stripe
			*/
			y = s->g.sp_i.drawSY;
			while (y < s->g.sp_i.drawEY)
			{
				s->g.d_c.texY = (int)floor(((double)y - ((double)s->g.img.scre_height / 2 - (double)s->g.sp_i.spH / 2)) * (double)s->g.ws.sp.height) / (double)s->g.sp_i.spH;
				s->g.d_c.color = s->g.ws.sp.data[s->g.ws.sp.width * s->g.d_c.texY + s->g.d_c.texX];
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
