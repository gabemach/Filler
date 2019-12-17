/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:21:27 by gmachado          #+#    #+#             */
/*   Updated: 2019/12/16 16:32:40 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void    place_piece(t_piece *piece, t_map *map)
{
    ft_putnbr(piece->loc_y);
    ft_putchar(' ');
    ft_putnbr(piece->loc_x);
    ft_putchar(' ');
    map->hmn_pos_y = piece->loc_y;
    map->hmn_pos_x = piece->loc_x;
}

/*
**  Sets up map and piece arrays
*/

int     parse_arrays(t_map *map, t_piece *piece)
{
    char    *line;

    while (get_next_line(0, &line) == 1)
    {
        if (ft_strncmp(line, "Plateau", 7 == 0))
        {
            parse_map(line, map);
            ft_strdel(&line);
        }
        else if (ft_strncmp(line, "Piece", 4))
        {
            parse_piece_size(piece, line);
            return (1);
        }
        else
            ft_strdel(&line);
    }
    return (0);
}

void	init_structs(t_map *map, t_piece *piece)
{
	map->map = 0;
	map->max_size_y = 0;
	map->max_size_x = 0;
	map->player_number = 0;
    map->hmn_pos_x = 0;
    map->hmn_pos_y = 0;
    map->opp_pos_x = 0;
    map->opp_pos_y = 0;
    piece->x_size = 0;
    piece->y_size = 0;
    piece->x_start = 0;
    piece->y_start = 0;
    piece->x_end = 0;
    piece->y_end = 0;
    piece->latest_x = 0;
    piece->latest_y = 0;
}

int	main(void)
{
	t_map	*map;
	t_piece	*piece;

	map = (t_map *)malloc(sizeof(*map));
	piece = (t_piece *)malloc(sizeof(*piece));
	init_structs(map, piece);
    who_is_who(map);
	while (1)
	{
		parse_arrays(map, piece);
		if (how_to_fill(piece, map) == 1)
        {
            if (endgame (piece, map) == 1)
            {
                place_piece(piece, map);
                exit(1);
            }
        }
	}
	free(map);
	free(piece);
	return (0);
}
