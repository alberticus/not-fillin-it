/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:29:32 by dysotoma          #+#    #+#             */
/*   Updated: 2018/03/19 19:29:35 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#define ALPHA char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define XY int y = board[0]; int x = board[1]
#define COUNT int index = 0; int count = 0

int		place_piece(char **map, char *piece, int *board, int i)
{
	ALPHA;
	XY;
	COUNT;
	if (can_place(map, piece, board))
	{
		while (piece[index])
		{
			if (piece[index] != '\n' && piece[index] != '.')
				map[y][x + count] = alpha[i];
			count++;
			index++;
			if (piece[index] == '\n')
			{
				count = 0;
				y++;
				index++;
			}
		}
		return (1);
	}
	return (0);
}

void	remove_piece(char **map, char *alpha, int dimension, int i)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < dimension)
	{
		while (x < dimension)
		{
			if (map[y][x] == alpha[i])
				map[y][x] = '.';
			x++;
		}
		x = 0;
		y++;
	}
	return ;
}

int		can_place(char **map, char *piece, int *dimension)
{
	int	count;
	int	index;
	int	y;
	int	x;

	count = 0;
	index = 0;
	y = dimension[0];
	x = dimension[1];
	while (piece[index])
	{
		if ((piece[index] == '#' && map[y][x + count] != '.')
			|| (((x + count) >= dimension[2] || y >= dimension[2]) &&
			piece[index] == '#'))
			return (0);
		index++;
		count++;
		if (piece[index] == '\n')
		{
			y++;
			count = 0;
			index++;
		}
	}
	return (1);
}
