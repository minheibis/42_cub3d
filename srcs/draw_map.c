#include "cub3d.h"

int		ft_draw_map(t_s *s)
{
	if ((ft_all_init(s)))
		return (s->rv);
	if (s->flag == 2)
	{
		/*
		**deal key
		*/
		mlx_hook(s->g.win, X_EVENT_KEY_PRESS, (1L<<0), &ft_deal_key, s);
		//not sure but bug on the mlx.hook close
		//mlx_hook(g.win, X_EVENT_KEY_EXIT, (1L<<0), &close, &g);
		/*
		**hook main loop
		*/
		mlx_loop_hook(s->g.mlx, &ft_main_loop, s);
		mlx_loop(s->g.mlx);
	}
	else
		ft_main_loop(s);
	return (0);
}

int		ft_all_init(t_s *s)
{
	ft_window_init(s);
	ft_img_init(s);
	ft_player_init(s);
	if ((s->rv = ft_wall_sp_init(s)))
		return (s->rv);
	ft_col_init(s);
	return (0);
}
