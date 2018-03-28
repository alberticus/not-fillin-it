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
	char	*newpiece;
	int		unwantedrows;
	int		copyindex;

	index = 0;
	unwantedrows = 0;
	newpiece = ft_strnew(ft_strlen(piece));
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
		newpiece[index] = piece[copyindex + index];
		index++;
	}
	return (newpiece);
}

static char	*moveleft(char *piece)
{
	int index;
	
	index = 0;
	char *newpiece;
	int unwantedcolumns;
	int copyindex;
	
	index = 0;
	newpiece = ft_strnew(ft_strlen(piece));
	copyindex = 0;
	
	

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

