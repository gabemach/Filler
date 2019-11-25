/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:21:27 by gmachado          #+#    #+#             */
/*   Updated: 2019/11/24 21:22:11 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int     parse_arrays(t_map *map, t_piece *piece)
{
    char    *line;

    while (get_next_line(0, &line) == 1)
    {
        if (ft_strncmp(line, "Plateau", 7 == 0))
        {
            read_map(line, map);
            ft_strdel(&line);
        }
        else if (ft_strncmp(line, "Piece", 4))
        {
            parse_piece(piece, line);
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
	map->current_player = 0;
}

int	main(void)
{
	t_map	*map;
	t_piece	*piece;

	map = (t_map *)malloc(sizeof(*map));
	piece = (t_piece *)malloc(sizeof(*piece));
	init_structs(map, piece);
	while (1)
	{
		parse_arrays(map, piece);
		
	}
	free(map);
	free(piece);
	return (0);
}
