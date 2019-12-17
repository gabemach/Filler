/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:14:35 by gmachado          #+#    #+#             */
/*   Updated: 2019/12/16 16:35:21 by gmachado         ###   ########.fr       */
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
	int			player_number;
	char		*hmn;
	int			hmn_pos_x;
	int			hmn_pos_y;
	char		*opp;
	int			opp_pos_x;
	int			opp_pos_y;
}				t_map;

typedef struct	s_piece
{
	char		**piece;
	int			x_size;
	int			x_real;
	int			y_size;
	int			y_real;
	int			x_start;
	int			y_start;
	int			x_end;
	int			y_end;
	int			such_touch;
	int			much_touch;
	int			loc_x;
	int			loc_y;
	int			latest_x;
	int			latest_y;
}				t_piece;

void	current_player(t_map *map);
void	read_map(char *line, t_map *map);
int		parse_arrays(t_map *map, t_piece *piece);
void	place_piece(t_piece *piece, t_map *map);
void	parse_piece_size(t_piece *piece, char *line);
void	parse_map(char *line, t_map *map);
void	who_is_who(t_map *map);
int		valid_spot(t_piece *piece, t_map *map, int x, int y);

#endif