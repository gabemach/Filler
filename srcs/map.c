/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:43:21 by gmachado          #+#    #+#             */
/*   Updated: 2019/10/31 13:43:21 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void    find_pos(t_map *map, char *str, int i)
{
    int         x_pos;
    static int  y_pos;

    if (y_pos == map->max_size_y)
        return ;
    y_pos = 0;
    while (++y_pos < map->max_size_y)
    {
        x_pos = 0;
        while (++x_pos < map->max_size_x)
        {
            if (map->map[y_pos][x_pos] == map->p1[0] ||
                    map->map[y_pos][x_pos] == map->p1[1])
                {
                    map->p1_pos_y = y_pos;
                    map->p1_pos_x = x_pos;
                }
            if (map->map[y_pos][x_pos] == map->p2[0] ||
                    map->map[y_pos][x_pos] == map->p2[1])
                {
                    map->p2_pos_y = y_pos;
                    map->p2_pos_x = x_pos;
                }
        }
    }
}

void    fill_map(t_map *map)
{
    char    *line;
    int     i;

    i = 0;
    get_next_line(0, &line);
    ft_strdel(&line);
    map->map = (char **)malloc(sizeof(char *) * (map->max_size_y + 1));
    while (i++ <= map->max_size_y - 1)
    {
        get_next_line(0, &line);
        map->map[i] = ft_strdup((const char *)(&line[4]));
        ft_strdel(&line);
    }
    find_pos(map, line, i);
}

void    read_map_size(char *line, t_map *map)
{
    int     i;
    int     temp;
    
    i = 0;
    while (line[i])
    {
        temp = 0;
        while (ft_isdigit(line[i]) == 0 && line[i])
        {
            temp += line[i] - 48;
            if (ft_isdigit(line[i + 1]) == 0)
                temp *= 10;
            i++;
        }
        if (map->max_size_y == 0)
            map->max_size_y = temp;
        else if (map->max_size_x == 0)
            map->max_size_x = temp;
        i++;
    }
    fill_map(map);
}