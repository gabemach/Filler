# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 12:00:34 by gmachado          #+#    #+#              #
#    Updated: 2019/12/16 17:30:46 by gmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gmachado.filler

HEADER = -I ./includes/filler.h\

ARCHIVE = \
	  -L includes/libft -l ft \
	  -L includes ft_printf -l ftprintf \

CFLAGS = -Wall -Wextra -Werror -c -g

CFILES = \
		./srcs/main.c \
		./srcs/map.c \
		./srcs/pieces.c \
		./srcs/players.c \
		./srcs/checker1.c \
		./srcs/checker2.c \
		./srcs/misc.c \

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(CFILES)
	@ echo Compiling...
	@ make -C includes/libft
	@ make -C includes/ft_printf
	@ gcc $(CFLAGS) -o $(NAME) $(ARCHIVE) $(CFILES)
	@ echo Finished Compiling! Run with ./resources/filler program
clean:
	@ make -C ./includes/libft clean
	@ make -C ./includes/ft_printf clean
	@ rm -f $(OFILES)

fclean: clean
	@ make -C ./includes/libft fclean
	@ make -C ./includes/ft_printf fclean
	@ rm -f $(NAME)
