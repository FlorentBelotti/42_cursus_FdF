# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 15:13:13 by fbelotti          #+#    #+#              #
#    Updated: 2024/04/11 22:57:35 by fbelotti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	FdF

CC =	gcc
RM =	rm -f

CFLAGS = -Wall -Wextra -Werror -g
CFLAGS += -I./libft -I./minilibx-linux
MLXFLAGS = -L./minilibx-linux -lmlx -L/usr/X11R6/lib -lX11 -lXext
LDFLAGS = -L./libft -lft

SRCS =	./FdF_parsing/FdF_parsing.c ./FdF_parsing/FdF_node_management.c \
		./FdF_errors/FdF_line_error.c ./FdF_errors/FdF_token_error.c \
		./FdF_parsing/FdF_memory_management.c \
		./FdF_mlx_management/Minilibx_creation.c \
		./FdF_mlx_management/Minilibx_key_handling.c \
		./FdF_tester/FdF_print.c \
		./FdF_utils/FdF_size_utils.c ./FdF_utils/FdF_bresenham_utils.c \
		./FdF_utils/FdF_list_utils.c ./FdF_utils/FdF_draw_utils.c \
		./FdF_utils/FdF_mvt_utils.c \
		./FdF_draw/FdF_bresenham.c ./FdF_draw/FdF_isometric.c \
		./FdF_draw/FdF_offset.c ./FdF_draw/FdF_clear_draw.c \
		./FdF_main.c \

OBJS =	$(SRCS:.c=.o)

all: announce libft mlx $(NAME) finished

announce:
	@echo "Author: Florent Belotti"
	@echo "Project: Fil_de_Fer"

$(NAME):	$(OBJS) libft mlx
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(MLXFLAGS) -lm -o $(NAME)
	@echo "Compilation of $(NAME) finished."

libft:
	@make -C ./libft

mlx:
	@make -C ./minilibx-linux

clean :
	@$(RM) $(OBJS)
	@make -C ./libft clean
	@make -C ./minilibx-linux clean
	@echo "Cleaned."

fclean : clean
	@$(RM) $(NAME)
	@make -C ./libft fclean
	@echo "Fully cleaned."

re : fclean all

finished:
	@echo "Make process finished."

.PHONY: all clean fclean re libft mlx announce finished
