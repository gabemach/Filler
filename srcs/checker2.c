/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:19:59 by gmachado          #+#    #+#             */
/*   Updated: 2019/12/13 17:19:59 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int endgame(t_piece *piece, t_map *map)
{
    int x;
    int y;
    int place;

    y = 0;
    piece->latest_x = 0;
    piece->latest_y = 0;
    place = 0;
    while (y++ < map->max_size_y)
    {
        x = 0;
        while (x++ < map->max_size_x)
        {
            place = valid_spot(piece, map, x, y);
            if (place == 0)
            {
                place_piece(piece, map);
                return (0);
            }
        }
    }
    return (1);
}