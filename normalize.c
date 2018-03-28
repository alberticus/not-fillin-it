/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsai <atsai@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:21:02 by atsai             #+#    #+#             */
/*   Updated: 2018/03/27 17:01:43 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static char	*moveup(char *piece)
{
	int		index;
	char	newpiece[20];
	int		unwantedrows;
	int		copyindex;

	index = 0;
	unwantedrows = 0;
	while (piece[index] != '#')
	{
		if (piece[index] == '\n')
			unwantedrows++;
		index++;
	}
	copyindex = unwantedrows * 5;
	index = 0;
	while (piece[index])
	{
		if (piece[index] == '\n')

			copyindex++;
		newpiece[index] = piece[copyindex + index];
		index++;
	}
	newpiece[index] = '\0';
	return (newpiece);
}

char		**normalize(char **piece)
{
	char	**normal_piece;
	int		i;

	if (!(normal_piece = (char**)malloc(sizeof(char*) * 4)))
		return (NULL);
	i = 0;
	while (piece[i])
	{
		if (!(normal_piece[i] = (char*)malloc(sizeof(char) * 5)))
			return (NULL);
		if (piece[i][0] == '#')
			normal_piece[i] = piece[i];
		normal_piece[i] = moveleft(moveup(piece[i]));
		i++;
	}
	return (normal_piece);
}

