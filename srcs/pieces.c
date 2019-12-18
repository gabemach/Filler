/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:13:30 by gmachado          #+#    #+#             */
/*   Updated: 2019/11/24 16:13:30 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void    actual_piece_size(t_piece *piece)
{
    int     x;
    int     y;

    y = 0;
    piece->y_start = piece->y_size;
    piece->x_start = piece->x_size;
    while (y++ < piece->y_size)
    {
        x = 0;
        while (x++ < piece->x_size)
            if (piece->piece[y][x] == '*')
            {
                if (x < piece->x_start)
                    piece->x_start = x;
                else if (x > piece->x_end)
                    piece->x_end = x;
                if (y < piece->y_start)
                    piece->y_start = y;
                else if (y < piece->y_end)
                    piece->y_end = y;
            }
    }
    piece->x_real = (piece->x_end - piece->x_start) + 1;
    piece->y_real = (piece->y_end - piece->y_start) + 1;
}

void    fill_piece(t_piece *piece)
{
    char    *line;
    int     i;

    i = 0;
    if (piece->piece != NULL)
        free(piece->piece);
    piece->piece = (char **)malloc(sizeof(char *) * (piece->y_size + 1));
    while (i < piece->y_size)
    {
        get_next_line(0, &line);
        piece->piece[i]= (char *)malloc(sizeof(char *) * (piece->x_size + 1));
        piece->piece[i] = ft_strcpy(piece->piece[i], (const char *)line);
        i++;
        ft_strdel(&line);
    }
}

void    parse_piece_size(t_piece *piece, char *line)
{
    int     i;
    int     temp;

    i = 0;
    while (line[i])
    {
        temp = 0;
        while (ft_isdigit(temp + 1) == 0 && line[temp])
        {
            temp += line[i] - 48;
            if (ft_isdigit(line[i + 1]) == 0)
                temp *= 10;
            i++;
        }
        if (piece->y_size == 0)
            piece->y_size = temp;
        else if (piece->x_size == 0)
            piece->x_size = temp;
        i++;
    }
    ft_strdel(&line);
    fill_piece(piece);
}