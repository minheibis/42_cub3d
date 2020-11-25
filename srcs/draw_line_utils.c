#include "cub3d.h"

int		to_coord(int x, int y, t_s *s)
{
	int	len;

	len = y * s->g.img.scre_width + x;
	return (len);
}

int		ft_decide_wall(t_s *s)
{
	if (s->g.h_c.side == 0)
	{
		if (s->g.r.rayDirY < 0)
			s->g.ws.now = s->g.ws.N;
		else
			s->g.ws.now = s->g.ws.S;
	}
	else
	{
		if (s->g.r.rayDirX > 0)
			s->g.ws.now = s->g.ws.E;
		else
			s->g.ws.now = s->g.ws.W;
	}
	return (0);
}

int			ft_draw_line_calc(t_s *s)
{
	/*
	**calculate value of wallX
	*/
	if (s->g.h_c.side == 0)
		s->g.d_c.wallX = s->g.p.posX + s->g.h_c.prepWallDist * s->g.r.rayDirX;
	else
		s->g.d_c.wallX = s->g.p.posY + s->g.h_c.prepWallDist * s->g.r.rayDirY;
	s->g.d_c.wallX -= floor(s->g.d_c.wallX);
	//printf
	// printf("ft_draw_line_calc: s->g.d_c.wallX: [%lf]\n", s->g.d_c.wallX);
	/*
	**x coordinate on the texture
	**	depend on the way tex file is read
	*/
	if ((s->g.h_c.side == 0 && s->g.r.rayDirY < 0) || (s->g.h_c.side == 1 && s->g.r.rayDirX > 0))
		s->g.d_c.texX = floor(s->g.d_c.wallX * s->g.ws.now.width);
	else
		s->g.d_c.texX = floor((1 - s->g.d_c.wallX) * s->g.ws.now.width);
	//printf
	// printf("ft_draw_line_calc: s->g.d_c.texX: [%d]\n", s->g.d_c.texX);
	/*
	**how much to increase the texture coordinate per screen pixel
	*/
	s->g.d_c.step = (double)s->g.ws.now.height / s->g.d_c.lineH;
	// printf("ft_draw_line_calc: s->g.d_c.step: [%lf]\n", s->g.d_c.step);
	/*
	**starting texture coordinate
	** different from old main
	*/
	if (s->g.d_c.lineH > s->g.img.scre_height)
		s->g.d_c.texPos = s->g.ws.now.height * ((1 - (double)s->g.img.scre_height / (double)s->g.d_c.lineH) / 2);
	else
		s->g.d_c.texPos = 0;
	// printf("ft_draw_line_calc: cel: s->g.img.scre_height: [%d]\n", s->g.img.scre_height);
	// printf("ft_draw_line_calc: cel: s->g.d_c.lineH: [%d]\n", s->g.d_c.lineH);
	// printf("ft_draw_line_calc: cel: s->g.d_c.drawS: [%d]\n", s->g.d_c.drawS);
	// printf("ft_draw_line_calc: s->g.d_c.texPos: [%lf]\n", s->g.d_c.texPos);
	return (0);
}

int		ft_draw_line_draw(t_s *s, int x)
{
	int	y;

	// printf("ft_draw_line_draw: cel: s->map.cel_col_int: [%x]\n", s->map.cel_col_int);
	// printf("ft_draw_line_draw: cel: s->map.flo_col_int: [%x]\n", s->map.flo_col_int);
	y = 0;
	//printf
	// printf("ft_draw_line_draw: cel: s->g.d_c.drawS: [%d]\n", s->g.d_c.drawS);
	// printf("ft_draw_line_draw: cel: s->g.d_c.drawE: [%d]\n", s->g.d_c.drawE);

	while (y < s->g.d_c.drawS)
	{
		s->g.img.data[to_coord(x, y, s)] = s->map.cel_col_int;
		//printf
		printf("ft_draw_line_draw: cel: y: [%d]\n", y);
		printf("ft_draw_line_draw: cel: s->map.flo_col_int: [%d]\n", s->map.cel_col_int);
		printf("ft_draw_line_draw: s->g.img.data: %d: [%d]\n", to_coord(x, y, s), s->g.img.data[to_coord(x, y, s)]);
		y++;
	}
	while (y < s->g.d_c.drawE)
	{
		/*
		**cast the texture coordinate to integer, ans mask with (texHeight - 1) in case of overflow
		** different from old main
		*/
		s->g.d_c.texY = floor(s->g.d_c.texPos);
		s->g.d_c.color = s->g.ws.now.data[s->g.ws.now.width * s->g.d_c.texY + s->g.d_c.texX];
		s->g.img.data[to_coord(x, y, s)] = s->g.d_c.color;
		s->g.d_c.texPos += s->g.d_c.step;
		//printf
		printf("ft_draw_line_draw: wall: y: [%d]\n", y);
		printf("ft_draw_line_draw: wall: s->g.d_c.color: [%d]\n", s->g.d_c.color);
		printf("ft_draw_line_draw: s->g.img.data: %d: [%d]\n", to_coord(x, y, s), s->g.img.data[to_coord(x, y, s)]);
		y++;
	}
	while (y < s->g.img.scre_height)
	{
		s->g.img.data[to_coord(x, y, s)] = s->map.flo_col_int;
		//printf
		printf("ft_draw_line_draw: flo: y: [%d]\n", y);
		printf("ft_draw_line_draw: flo: s->map.flo_col_int: [%d]\n", s->map.flo_col_int);
		printf("ft_draw_line_draw: s->g.img.data: %d: [%d]\n", to_coord(x, y, s), s->g.img.data[to_coord(x, y, s)]);
		y++;
	}
	return (0);
}
