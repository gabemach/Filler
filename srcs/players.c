/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:12:55 by gmachado          #+#    #+#             */
/*   Updated: 2019/10/31 15:12:55 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	assign_token(t_map *map)
{
	if (map->player_number == 1)
	{
		map->hmn = "Oo";
		map->opp = "Xx";
	}
	if (map->player_number == 2)
	{
		map->hmn = "Xx";
		map->opp = "Oo";
	}
}

/*
**	determines which player the algorithm has been assigned to
*/

void	who_is_who(t_map *map)
{
	char	*line;
	
    get_next_line(0, &line);
	if (ft_strncmp(line, "$$$", 2) == 0 && map->player_number == 0)
	{
		if (ft_strstr(line, "p1"))
			map->player_number = 1;
		if (ft_strstr(line, "p2"))
			map->player_number = 2;
		assign_token(map);
	}
    ft_strdel(&line);
}