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
#define y 0
#define x 1
#define d 2
#define ALPHA char *alpha;

static int	*board_d(int *board)
{
	board[d]++;
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
	board[x] = 0;
	board[y]++;
	return (board);
}

static void	reset_map(char **map, char **pieces, int *board, int i)
{
	i = 0;
	while (pieces[i])
	{
		remove_piece(map, pieces[i], board[d], i);
		i++;
	}
	board_d(board);
	return ;
}

int			solve(char **map, char **pieces, int *board, int i)
{
	ALPHA;
	alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (board[x] == board[d] && board[y] == board[d] && is_done(pieces))
		return (0);
	else if (board[x] == board[d] && board[y] == board[d] && is_done(pieces))
		reset_map(map, pieces, board, i);
	if (board[x] < board[d] && board[y] < board[d])
	{
		while (pieces[i])
		{
			if (can_place())
			{
				if (place_piece(map, pieces[i], board, i))
					board[x]++;
				if (!(solve(map, pieces, board, i++)))
					return (solve(map, pieces, board, i));
				remove_piece(map, alpha, board[d], i);
			}
			i++;
		}
		solve(map, pieces, board, 0);
	}
	else if (board[x] == board[d] && board[y] < board[d])
		board = reset(board);
	return (solve(map, pieces, board, i));
}
