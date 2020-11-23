NAME		= cub3D
SRCS_DIR	= ./srcs
INCLUDE_DIR	= -I/usr/include -Iincludes -Imlx_linux
SRCS_NAME	= test_utils.c \
				cub_list_utils.c \
				cub3d.c \
				error.c \
				get_next_line_utils.c \
				get_next_line.c \
				init.c \
				input_check.c \
				read_cub.c \
				parse_element.c \
				parse_map.c \
				parse_map_set.c \
				parse_map_utils.c \
				ft_isnum.c \
				check_map.c \
				check_map_utils.c \
				find_wall.c \
				check_p.c \
				check_p_utils.c \
				draw_map.c \
				deal_key.c \
				deal_key_utils.c \
				all_init.c \
				all_init_utils.c \
				main_loop.c \
				main_loop_utils.c \
				ray_wall_x.c \
				calc_hit_utils.c \
				draw_line_utils.c \

SRCS		= $(addprefix $(SRCS_DIR)/,$(SRCS_NAME))
OBJS		= $(SRCS:.c=.o)
LIBS		= -lmlx -lXext -lX11 -lm
CC			= gcc
CFLAGS		= -g -Wall -Wextra -Werror $(INCLUDE_DIR)
RM			= rm -f

$(NAME): $(OBJS)
	$(MAKE) -C ./mlx_linux
	cp ./mlx_linux/libmlx.a .
	$(CC) $(OBJS) $(CFLAGS) -L. -L.mlx_linux $(LIBS) -o $(NAME)

all		: $(NAME)

clean	:
	$(MAKE) clean -C ./mlx_linux
	$(RM) $(OBJS)

fclean	: clean
	$(RM) ./libmlx.a
	$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
