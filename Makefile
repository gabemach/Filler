# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 12:00:34 by gmachado          #+#    #+#              #
#    Updated: 2019/11/24 21:52:02 by gmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gmachado.filler

INCLUDES = \
		-L ./includes/libft
		-L ./includes/ft_printf

HEADER = \

CFLAGS = -Wall -Wextra -Werror -c -g

CFILES = \
		./srcs/main.c \
		./srcs/map.c\
		./srcs/pieces.c\
		./srcs/players.c\
		./srcs/checker.c\

OFILES = \

all: $(NAME)