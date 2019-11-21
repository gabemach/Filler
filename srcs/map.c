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

void    read_map(char *line, t_map *map)
{
    int     i;
    char    **temp;

    i = 0;
    while (get_next_line(0, &line))
    {
        map->max_size_y++;
        free(line);
    }
    free(&line);
    map->map_y = (char **)malloc(sizeof(char *) * (map->max_size_y + 1));
    while (i++ < map->max_size_y)
        map->map_x[i] = (char)ft_memalloc(sizeof(char) * (map->max_size_x + 1));
    while (temp[map->max_size_x])
        map->max_size_x++;
    
}