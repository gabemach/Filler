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

void    fill_map(t_map *map)
{
    int     i;
    char    *line;
    char    **temp;

    i = 0;
    get_next_line(0, &line);
    temp = line;
    free(&line);
    map->map = (char **)malloc(sizeof(char *) * (map->size_y + 1));
    while (temp[map->size_x])
        map->size_x++;
    
}