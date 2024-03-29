# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 12:00:34 by gmachado          #+#    #+#              #
#    Updated: 2019/12/17 18:02:15 by gmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = resources/players/gmachado.filler

HEADER = \
		-I ./includes/filler.h

ARCHIVE = \
	  -L includes/libft -l ft \
	  -L includes/ft_printf -l ftprintf \

CFLAGS = -Wall -Wextra -Werror -g

SRCS = \
		./srcs/main.c \
		./srcs/map.c \
		./srcs/pieces.c \
		./srcs/players.c \
		./srcs/checker1.c \
		./srcs/checker2.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@ echo Compiling...
	@ make -C includes/libft
	@ make -C includes/ft_printf
	@ gcc $(CFLAGS) -o $(NAME) $(SRCS) $(ARCHIVE) -fsanitize=address
	@ echo Finished Compiling! Run with ./resources/filler program
clean:
	@ make -C ./includes/libft clean
	@ make -C ./includes/ft_printf clean
	@ rm -f $(OFILES)

fclean: clean
	@ make -C ./includes/libft fclean
	@ make -C ./includes/ft_printf fclean
	@ rm -f $(NAME)

re: fclean all