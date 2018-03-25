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

static int	been_placed(char *str, int i, int flag)
{
	char	*alpha;
	char	*alphas;

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
		alphas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		alpha[i] = alphas[i];
	}
	return (0);
}

void		place_piece(char **map, char *piece, int board, int i)
{
	char	*alpha;

	alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (been_placed(alpha, i, 0))
	{

	}

}
