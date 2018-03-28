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

static int	*board_d(int *board)
{
	board[2]++;
	return (board);
}

static int	is_done(char **pieces)
{
	int i;

	i = 0;
	while (pieces[i])
	{
		if (been_placed(pieces[i], i, 0) == 1)
			i++;
		return (0);
	}
	return (1);
}

static int	*reset(int *board)
{
	board[1] = 0;
	board[0]++;
	return (board);
}

static void	reset_map(char **map, char **pieces, int *board, int i)
{
	i = 0;
	while (pieces[i])
	{
		remove_piece(map, pieces[i], board[2], i);
		i++;
	}
	board_d(board);
	return ;
}

void		solve(char **map, char **pieces, int *board, int i)
{
	ALPHA;
	if (board[1] == board[2] && board[0] == board[2] && is_done(pieces))
		return (0);
	else if (board[1] == board[2] && board[0] == board[2] && is_done(pieces))
		reset_map(map, pieces, board, i);
	if (board[1] < board[2] && board[0] < board[2])
	{
		while (pieces[i])
		{
			if (can_place(map, pieces[i], board))
			{
				if (place_piece(map, pieces[i], board, i))
					board[1]++;
				if (!(solve(map, pieces, board, i++)))
					return (solve(map, pieces, board, i));
				remove_piece(map, alpha, board[2], i);
			}
			i++;
		}
		solve(map, pieces, board, 0);
	}
	else if (board[1] == board[2] && board[0] < board[2])
		return (solve(map, pieces, reset(board), i));
	return (0);
}
