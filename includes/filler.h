/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:14:35 by gmachado          #+#    #+#             */
/*   Updated: 2019/10/24 12:15:51 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

typedef struct	s_map
{
	int	fd1;
	int	fd2;
	int	x;
	int	y;
}		t_map;

typedef struct	s_piece
{
	int	fd1;
	int	fd2;
	int	x;
	int	y;
}		t_piece;

#endif
