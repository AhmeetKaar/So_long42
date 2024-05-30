NAME = so_long
CC = gcc
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
MLXDIR = minilibx
MLX = $(MLXDIR)/libmlx.a
SRCS = main.c flood_fill.c control_map.c window.c step.c error.c
OBJS := $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTDIR) 
	make -C $(LIBFTDIR) 
	make -C $(MLXDIR)
	$(CC) $(FLAGS) $(NAME).c $(OBJS) $(LIBFT) $(MLX) $(FRAMEWORKS) -o $(NAME)

clean: 
	rm -rf $(OBJS)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re