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

int		been_placed(char *str, int i, int flag)
{
	char	*alpha;

	alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (flag == 0)
	{
		if (str[i] != alpha[i])
			return (0);
		alpha[i] = 0;
		return (1);
	}
	if (flag == 1)
	{
		alpha[i] = str[i];
	}
	return (0);
}

void	place_piece(char **map, char *piece, int *board, int i)
{
	char	*alpha;

	alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (been_placed(alpha, i, 0))
	{

	}

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
	been_placed(alpha, i, 1);
	return ;
}

int		can_place(char **map, char *piece, int dimension)
{
	int index;
	int x;
	int y;

	index = 0;
	x = 0;
	y = 0;
	while (piece)
	{
		if (piece[index] == '\n')
		{
			x = 0;
			y++;
		}
		if (piece[index] == '#' && map[x][y] != '.')
			return (0);
		index++;
		x++;
		// we need to find a way to account for the board if the
		// tetrimino goes out of bounds of the board
	}
}
