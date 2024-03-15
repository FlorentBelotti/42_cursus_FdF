# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 15:13:13 by fbelotti          #+#    #+#              #
#    Updated: 2024/03/14 13:50:22 by fbelotti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	FdF

CC =	gcc
RM =	rm -f

CFLAGS = -Wall -Wextra -Werror -g
CFLAGS += -I./libft
LDFLAGS = -L./libft -lft

SRCS =	./FdF_parsing/FdF_parsing.c ./FdF_parsing/FdF_node_management.c \
		./FdF_errors/FdF_line_error.c ./FdF_errors/FdF_token_error.c \
		./FdF_parsing/FdF_memory_management.c \
		./FdF_main_test.c \

OBJS =	$(SRCS:.c=.o)

all: libft $(NAME)

${NAME}:	$(OBJS) libft
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

libft:
		make -C ./libft

clean :
		$(RM) $(OBJS)
		make -C ./libft clean

fclean : clean
		$(RM) $(NAME)
		make -C ./libft fclean

re : fclean $(NAME)

.PHONY: all clean fclean re libft
