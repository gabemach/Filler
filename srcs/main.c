/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:21:27 by gmachado          #+#    #+#             */
/*   Updated: 2019/10/24 12:21:51 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	init_structs(t_map *map, t_piece *piece)
{
	
}

int	main(void)
{
	t_map	*map;
	t_piece	*piece;

	map = (t_map)malloc(sizeof(*map));
	piece = (t_piece)malloc(sizeof(*piece));
	init_structs(&map, &piece);
	free(map);
	free(piece);
	return (0);
}
