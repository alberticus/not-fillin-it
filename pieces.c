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

move_piece

place_piece

static set_pieces(char **map)

char	**make_pieces(char *map)
{
	char	**pieces;
	int		index;
	int		x;
	int		y;

	index = 0;
	x = 0;
	y = 0;
	if (!(pieces = ft_strsplit(*map, '\n')))
		return (NULL);

}
