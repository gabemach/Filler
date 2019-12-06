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

int do_they_touch(t_piece *piece, t_map *map)
{
    int y;
    int x;

    y = 0;
    while (y++ < map->max_size_y - 3)
    {
        x = 0;
        while (x++ < map->max_size_x - 3)
        {
            if (map->map[y][x] == map->hmn[0] || map->map[y][x] == map->hmn[1])
                if (map->map[y][x + 3] == map->opp[0] || map->map[y][x - 3] ==
                    map->opp[0] || map->map[y][x + 3] == map->opp[1] ||
                    map->map[y][x - 3] == map->opp[1] || map->map[y + 3][x] ==
                    map->opp[0] || map->map[y - 3][x] == map->opp[0] ||
                    map->map[y + 3][x] == map->opp[1] || map->map[y - 3][x] ==
                    map->opp[1])
                    return (1);
        }
    return (0);
    }
}

int how_much_touch(t_piece *piece, t_map *map, int x, int y)
{
    int iy;
    int ix;
    int d;

    iy = 0;
    piece->much_touch = 0;
    while (iy++ < piece->y_size)
    {
        ix = 0;
        while (ix++ < piece->x_size)
            if (piece->piece[iy][ix] == '*')
            {
                d = 1;
                while (d++ < 4)
                    if (ix + x + d < map->max_size_x && ix + x - d > 0
                        && iy + y + d < map->max_size_y && iy + y - d > 0)
                        if (map->map[iy + y][ix + x + d] == map->opp[0] ||
                            map->map[iy + y][ix + x - d] == map->opp[0] ||
                            map->map[iy + y + d][ix + x] == map->opp[0] ||
                            map->map[iy + y - d][ix + x] == map->opp[0])
                            piece->much_touch += 4 - d;
            }
    }
    return (piece->much_touch);
}


int cover_1(t_piece *piece, t_map *map, int x, int y)
{
    int check;
    int spot_x;
    int spot_y;

    check = 0;
    spot_y = 0;
    if (piece->x_size > map->max_size_x || piece->y_size > map->max_size_y)
        return (0);
    while (check < 2)
        while (spot_y++ < map->max_size_y)
        {
            spot_x = 0;
            while (spot_x++ < map->max_size_x)
                if ((piece->piece[spot_y][spot_x] == '*' &&
                    piece->piece[spot_y][spot_x] == map->hmn[0]) ||
                    (piece->piece[spot_y][spot_x] == '*' && 
                    piece->piece[spot_y][spot_x] == map->hmn[1]))
                    check += 1;
            if (check != 1)
                return (1);
        }
    return (0);
}


int bottom_to_top(t_piece *piece, t_map *map)
{
    return (0);
}

int top_to_bottom(t_piece *piece, t_map *map)
{
    int x;
    int y;

    y = 0;
    while (y++ < map->max_size_y)
    {
        x = 0;
        while (x < map->max_size_x)
        {
            if (map->map[y][x] == map->hmn[0] || map->map[y][x] == map->hmn[1])
                return (1);
        }
    }
    return (0);
}

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
