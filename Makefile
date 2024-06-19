# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 15:13:13 by fbelotti          #+#    #+#              #
#    Updated: 2024/06/19 17:14:42 by fbelotti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fil_de_fer
AUTHOR = Florent Belotti

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./Includes -I./Includes/libft -I./Includes/minilibx-linux
MLXFLAGS = -L./Includes/minilibx-linux -lmlx -L/usr/X11R6/lib -lX11 -lXext
LDFLAGS = -L./Includes/libft -lft

SRCDIR = Src
OBJDIR = obj

SRCS =  $(SRCDIR)/FdF_parsing/FdF_parsing.c $(SRCDIR)/FdF_parsing/FdF_node_management.c \
		$(SRCDIR)/FdF_errors/FdF_line_error.c $(SRCDIR)/FdF_errors/FdF_token_error.c \
		$(SRCDIR)/FdF_parsing/FdF_memory_management.c \
		$(SRCDIR)/FdF_mlx_management/Minilibx_creation.c \
		$(SRCDIR)/FdF_mlx_management/Minilibx_key_handling.c \
		$(SRCDIR)/FdF_utils/FdF_size_utils.c $(SRCDIR)/FdF_utils/FdF_bresenham_utils.c \
		$(SRCDIR)/FdF_utils/FdF_list_utils.c $(SRCDIR)/FdF_utils/FdF_draw_utils.c \
		$(SRCDIR)/FdF_utils/FdF_mvt_utils.c \
		$(SRCDIR)/FdF_draw/FdF_bresenham.c $(SRCDIR)/FdF_draw/FdF_isometric.c \
		$(SRCDIR)/FdF_draw/FdF_offset.c $(SRCDIR)/FdF_draw/FdF_clear_draw.c \
		$(SRCDIR)/FdF_main.c

OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

DEPS = $(OBJS:.o=.d)

all: announce intro libft mlx $(NAME)

announce:
	@echo "\n==================================="
	@echo "Author: $(AUTHOR)"
	@echo "Project: $(NAME)"
	@echo "===================================\n"

intro:
	@echo "Starting the build process..."

$(NAME): $(OBJS)
	@echo "\nFil_de_fer:	libft: creating library..."
	@$(MAKE) -C ./Includes/libft > /dev/null
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(MLXFLAGS) -lm -o $@
	@echo "Fil_de_fer:	Executable $@ created."

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@echo Fil_de_fer:	Src:	compiling file $@
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

libft:
	@$(MAKE) -C ./Includes/libft > /dev/null

mlx:
	@$(MAKE) -C ./Includes/minilibx-linux > /dev/null

-include $(DEPS)

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C ./Includes/libft clean > /dev/null
	@$(MAKE) -C ./Includes/minilibx-linux clean > /dev/null
	@echo "Fil_de_fer:	Cleaned."

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C ./Includes/libft fclean > /dev/null
	@echo "Fil_de_fer:	Fully cleaned."

re: fclean all

debug: CFLAGS += $(DEBUG_FLAGS)
debug: re

.PHONY: all clean fclean re libft mlx announce intro
