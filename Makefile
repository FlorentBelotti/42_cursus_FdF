# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 15:13:13 by fbelotti          #+#    #+#              #
#    Updated: 2024/03/11 17:59:40 by fbelotti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./get_next_line/get_next_line_utils.c \
		./get_next_line/get_next_line.c \
		./Source/FdF_parsing_utils.c \
		./Source/FdF_main_test.c \
		./Source/FdF_parsing.c \
		./Source/FdF_line_error.c \
		./Source/FdF_token_error.c \
		./Source/FdF_split.c \
		./Source/FdF_data_fill.c \

CC =	gcc
RM =	rm -f
CFLAGS = -Wall -Wextra -Werror -g

NAME =	FdF

OBJS =	$(SRCS:.c=.o)

${NAME} : $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re
