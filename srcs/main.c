/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:21:27 by gmachado          #+#    #+#             */
/*   Updated: 2019/11/20 17:14:25 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	init_structs(t_map *map, t_piece *piece)
{
	map->map = 0;
	map->max_size_y = 0;
	map->max_size_x = 0;
	map->current_player = 0;
	map->p1 = "Oo";
	map->p2 = "Xx";
}

int	main(void)
{
	t_map	*map;
	t_piece	*piece;

	map = (t_map *)malloc(sizeof(*map));
	piece = (t_piece *)malloc(sizeof(*piece));
	init_structs(map, piece);
	free(map);
	free(piece);
	return (0);
}
