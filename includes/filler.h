/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:14:35 by gmachado          #+#    #+#             */
/*   Updated: 2019/11/20 17:14:21 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

typedef struct	s_map
{
	char		**map_y;
	char		*map_x;
	char		**map;
	int			max_size_x;
	int			max_size_y;
	int			current_player;
	char		*p1;
	int			p1_pos_x;
	int			p1_pos_y;
	char		*p2;
	int			p2_pos_x;
	int			p2_pos_y;
}				t_map;

typedef struct	s_piece
{
	int	piece_x;
	int	piece_y;
}		t_piece;

void	current_player(t_map *map);
void	read_map(char *line, t_map *map);

#endif
