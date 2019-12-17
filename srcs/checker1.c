/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:55:43 by gmachado          #+#    #+#             */
/*   Updated: 2019/11/13 14:55:43 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int try_spot(t_piece *piece, int xyz, int x, int y)
{
    if (xyz == 1)
    {
        piece->latest_x = x;
        piece->latest_y = y;
        return (0);
    }
    return (1);
}

int valid_spot(t_piece *piece, t_map *map, int x, int y)
{
    int xyz;
    int x1;
    int y1;

    y1 = 0;
    xyz = 0;
    if (piece->y_size + y > map->max_size_y ||
        piece->x_size + x > map->max_size_x)
        return (1);
    while (y1++ < piece->y_size - 1)
    {
        while (x1++ < piece->x_size - 1)
        {
            if (piece->piece[y1][x1] == '*' && (map->map[y + y1][x + x1] ==
                map->opp[0] || map->map[y + y1][x + x1] == map->opp[1]))
                return (1);
            if (piece->piece[y1][x1] == '*' && (map->map[y + y1][x + x1] ==
                map->hmn[0] || map->map[y + y1][x + x1] == map->opp[1]))
                xyz++;
        }
    }
    if (try_spot(piece, xyz, x, y) == 0)
        return (0);
    return (1);
}


int bottom_to_top(t_piece *piece, t_map *map)
{
    int x;
    int y;
    int place;

    y = map->max_size_y;
    piece->latest_y = 0;
    piece->latest_x = 0;
    place = 0;
    while (y-- > 0)
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

int top_to_bottom(t_piece *piece, t_map *map)
{
    int x;
    int y;
    int place;

    y = 0;
    piece->latest_y = 0;
    piece->latest_x = 0;
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

/*
**  Determines which direction the algorithm should check depending on
**  the player location.
*/

int how_to_fill(t_piece *piece, t_map *map)
{
    if (map->hmn_pos_y <= map->max_size_y / 2)
    {
        return (top_to_bottom(piece, map));
    }
    if (map->hmn_pos_y > map->max_size_y / 2)
    {
        return (bottom_to_top(piece, map));
    }
    return (0);
}
