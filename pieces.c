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

static int	been_placed(char *str, int i)
{
	char	*alpha;

	alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (str[i] != alpha[i])
		return (0)
	alpha[i] = 0;
	return (1);
}

void		place_piece(char **map, char *piece, int board, int i)
{
	char	*alpha;

	alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

void		remove_piece(char **map, char *alphabet, int dimension, int index)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	while (y < dimension)
	{
		while (x < dimension)
		{
			if (map[x][y] == alphabet[index])
				map[x][y] = '.';
			x++;
		}
		x = 0;
		y++;
	}
	been_placed(alphabet, index, 0);
}
