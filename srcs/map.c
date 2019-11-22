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
            //check piece
            return (1);
        }
        else
            ft_strdel(&line);
    }
    return (0);
}

void    find_pos(t_map *map, char *str, int i)
{
    int         x_pos;
    static int  y_pos;

    if (y_pos == map->max_size_y)
        return ;
    y_pos = 0;
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