#include "cub3d.h"

int		ft_ray_wall_x(t_s *s, int x)
{
	ft_calc_pos(s, x);
	ft_calc_hit(s);
	ft_calc_line(s);
	ft_draw_line(s, x);
	/*
	**add some for sprite
	*/
	return (0);
}

int		ft_calc_pos(t_s *s, int x)
{
	/*
	**calculate ray position and direction
	**	cameraX: x-coordinate in camera space,
	**	 the right side of the screen is 1, center is 0, left side is -1
	*/
	//printf
	// printf("ft_calc_pos: s->g.p.dirX: [%lf]\n", s->g.p.dirX);
	// printf("ft_calc_pos: s->g.p.dirY: [%lf]\n", s->g.p.dirY);
	s->g.r.cameraX = 1 - (x * 2 / (double)s->g.img.scre_width);
	s->g.r.rayDirX = s->g.p.dirX + s->g.p.planeX * s->g.r.cameraX;
	s->g.r.rayDirY = s->g.p.dirY + s->g.p.planeY * s->g.r.cameraX;
	//printf

	// printf("ft_calc_pos: s->g.p.posX: [%lf]\n", s->g.p.posX);
	// printf("ft_calc_pos: s->g.p.posY: [%lf]\n", s->g.p.posY);
	// printf("ft_calc_pos: s->g.p.dirX: [%lf]\n", s->g.p.dirX);
	// printf("ft_calc_pos: s->g.p.dirY: [%lf]\n", s->g.p.dirY);
	// printf("ft_calc_pos: s->g.p.planeX: [%lf]\n", s->g.p.planeX);
	// printf("ft_calc_pos: s->g.p.planeY: [%lf]\n", s->g.p.planeY);
	// printf("ft_calc_pos: s->g.r.cameraX: [%lf]\n", s->g.r.cameraX);
	// printf("ft_calc_pos: s->g.r.rayDirX: [%lf]\n", s->g.r.rayDirX);
	// printf("ft_calc_pos: s->g.r.rayDirY: [%lf]\n", s->g.r.rayDirY);

	/*
	**which box of the map we are in
	*/
	s->g.h_c.mapX = floor(s->g.p.posX);
	s->g.h_c.mapY = floor(s->g.p.posY);
	/*
	**length of ray from one x-side to next x-side or one y-side to next y-side
	** different from oldmain.c
	*/
	if (s->g.r.rayDirX == 0)
		s->g.h_c.deltaDistX = s->g.img.scre_width;
	else
		s->g.h_c.deltaDistX = sqrt(1 + (pow(s->g.r.rayDirY, 2) / pow(s->g.r.rayDirX, 2)));
	if (s->g.r.rayDirY == 0)
		s->g.h_c.deltaDistY = s->g.img.scre_height;
	else
		s->g.h_c.deltaDistY = sqrt(1 + (pow(s->g.r.rayDirX, 2) / pow(s->g.r.rayDirY, 2)));
	return (0);
}

int		ft_calc_hit(t_s *s)
{
	ft_calc_hit_init(s);
	ft_calc_hit_DDA(s);
	return (0);
}

int		ft_calc_line(t_s *s)
{
	/*
	**Calculate distance projected on camera direction
	** (Euclidean distance will give fisheye effect)
	** x and y are opposite from the old main
	*/
	if (s->g.h_c.side == 0)
		s->g.h_c.prepWallDist = (s->g.h_c.mapY + (1 - s->g.h_c.stepY) / 2 - s->g.p.posY) / s->g.r.rayDirY;
	else
		s->g.h_c.prepWallDist = (s->g.h_c.mapX + (1 - s->g.h_c.stepX) / 2 - s->g.p.posX) / s->g.r.rayDirX;
	//printf
	// printf("ft_calc_line: s->g.img.scre_height: [%d]\n", s->g.img.scre_height);
	// printf("ft_calc_line: s->g.h_c.prepWallDist: [%lf]\n", s->g.h_c.prepWallDist);
	/*
	** calculate height of line to draw on screen
	*/
	s->g.d_c.lineH = floor(s->g.img.scre_height / s->g.h_c.prepWallDist);
	//printf
	// printf("ft_calc_line: s->g.d_c.lineH: [%d]\n", s->g.d_c.lineH);
	/*
	**caluculate lowest and heighest pixel to fill in current stripe
	*/
	s->g.d_c.drawS = s->g.img.scre_height / 2 - s->g.d_c.lineH / 2;
	if (s->g.d_c.drawS < 0)
		s->g.d_c.drawS = 0;
	s->g.d_c.drawE = s->g.img.scre_height / 2 + s->g.d_c.lineH / 2;
	if (s->g.d_c.drawE >= s->g.img.scre_height)
		s->g.d_c.drawE = s->g.img.scre_height - 1;
	//printf
	// printf("ft_calc_line: s->g.d_c.drawS: [%d]\n", s->g.d_c.drawS);
	// printf("ft_calc_line: s->g.d_c.drawE: [%d]\n", s->g.d_c.drawE);
	return (0);
}

int		ft_draw_line(t_s *s, int x)
{
	ft_decide_wall(s);
	ft_draw_line_calc(s);
	ft_draw_line_draw(s, x);
	return (0);
}
