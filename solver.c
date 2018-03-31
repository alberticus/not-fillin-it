/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:56:53 by dysotoma          #+#    #+#             */
/*   Updated: 2018/03/21 21:56:59 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#define ALPHA char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/*
** board[0] = y
** board[1] = x
** board[2] = dimensions
*/

int			solve(char **map, char **pieces, int *board, int i)
{
	int row;
	int col;

	ALPHA;
	if (pieces[i] == NULL)
		return (1);
	row = 0;
	while (row < board[2] && board[2] < 15)
	{
		col = 0;
		while (col < board[2] && board[2] < 15)
		{
			board[0] = row;
			board[1] = col;
			if (place_piece(map, pieces[i], board, i))
			{
				if (solve(map, pieces, board, i + 1))
					return (1);
				remove_piece(map, alpha, board[2], i);
			}
			col++;
		}
		row++;
	}
	return (0);
}
