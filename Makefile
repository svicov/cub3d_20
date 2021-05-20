NAME = cub3D

SRCS =	get_next_line.c get_next_line_utils.c is_r_tekstury.c\
		pars1part.c pars_1part_2.c pars_1part_3.c init.c\
		pars2.c true_map.c ft_maxlen.c ft_error.c valid_map.c counting_sp.c \
		init_ab.c floor.c wall.c sprites.c sprites_utils.c update.c player.c \
		controls.c paint.c texture.c
		

OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -rf

CFLAGS =  -Wextra -Werror -Wextra -g

MFLAGS = -framework OpenGL -framework Appkit

all:	$(NAME) libmlx.a

%.o: %.c
	@$(CC) $(CFLAGS) -c -I./minilibx/ $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		@make -C libft
		@make -C minilibx
		@mv minilibx/libmlx.a .
		@mv libft/libft.a .
		@$(CC) $(CFLAGS) $(MFLAGS) -o $(NAME) -L. -lmlx -I./minilibx/ libft.a $(OBJS)
clean:		
		@$(RM) $(OBJS)
		@make clean -C minilibx

fclean:		clean
		@$(RM) $(NAME) cub3D.bmp libmlx.a

re:		fclean all

.PHONY:		all clean fclean re
