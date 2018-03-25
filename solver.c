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
#define dimension 2

void	solve(char **map, char **pieces, int *board, int i)
{
	char	*alpha;

	alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (board[y] < board[dimension] && board[x] < board[dimension])
		{
			if (pieces[i])
			{
				if (!(place_piece(map, pieces[i], board, i)))
					i++;
				board[x]++;
			}
			else if
				i = 0;
		}
}
