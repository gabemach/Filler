/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:14:35 by gmachado          #+#    #+#             */
/*   Updated: 2019/10/31 15:17:35 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

typedef struct	s_map
{
	char		**map;
	int			size_x;
	int			size_y;
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

#endif
