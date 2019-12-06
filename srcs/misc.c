/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:24:33 by gmachado          #+#    #+#             */
/*   Updated: 2019/12/04 15:24:33 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int ft_min(int a, int b)
{
    if (a < b)
        return (a);
    return (b);
}

int ft_max(int a, int b)
{
    if (a > b)
        return (a);
    return (b);
}

int distance(t_map *map)
{
    int dist_x;
    int dist_y;

    dist_x = ft_max(map->hmn_pos_x, map->opp_pos_x) -
                ft_min(map->hmn_pos_x, map->opp_pos_x);
    dist_y = ft_max(map->hmn_pos_y, map->opp_pos_y) -
                ft_min(map->hmn_pos_y, map->opp_pos_y);
    return (dist_x + dist_y);
}