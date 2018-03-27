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
	const char	*alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int			index;
	int			y;
	int			x;
	int			count;

	index = 0;
	y = board[0];
	x = board[1];
	count = 0;
	if (been_placed(alpha, i, 0))
		while (piece[index])
		{
			if (piece[index] == '\n')
			{
				count = 0;
				y++;
			}
			else if (piece[index] == '#')
				map[y][x + count] == alpha[i];
			index++;
			count++;
		}
	return ;
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

char	**normalize(char **str)
{
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
		if (piece[index] == '\n')
		{
			y++;
			count = 0;
		}
		if (piece[index] == '#' && map[y][x + count] != '.'
			|| map[y][x + count] >= dimension[2])
			return (0);
		index++;
	}
	return (1);
}
