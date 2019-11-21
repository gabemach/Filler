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

void	current_player(t_map *map)
{
	char	*line;
	
    get_next_line(0, &line);
	if (ft_strncmp(line, "$$$", 2) == 0 && map->current_player == 0)
	{
		if (ft_strstr(line, "p1"))
			map->current_player = 1;
		if (ft_strstr(line, "p2"))
			map->current_player = 2;
	}
    ft_strdel(&line);
}