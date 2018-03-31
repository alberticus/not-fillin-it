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
#define INIT int index; int rem; int timesmovedleft

static int	ft_wc(char **str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

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

/*
** rather than have the function make a new string and return it,
** I wrote it so that it changes the original string and returns it
*/

static int	moveleft_check(char *p)
{
	int i;
	int index;
	int rem;

	i = 0;
	rem = 0;
	while (i < 3)
	{
		index = 0;
		while (p[i + index] == '.')
			index += 5;
		if (p[i + index] == '#')
			return (rem);
		i++;
		rem++;
	}
	return (rem);
}

static char	*moveleft(char *p)
{
	INIT;
	index = 0;
	timesmovedleft = 0;
	rem = moveleft_check(p);
	while (timesmovedleft < rem)
	{
		if (!p[index])
		{
			index = 0;
			timesmovedleft++;
		}
		if (timesmovedleft == rem)
			break ;
		if (p[index + 1] == '#')
		{
			p[index] = '#';
			p[index + 1] = '.';
		}
		index++;
	}
	return (p);
}

char		**normalize(char **piece)
{
	char	**new_p;
	int		i;
	int		count;

	count = ft_wc(piece);
	if (!(new_p = (char **)ft_memalloc(sizeof(char *) * (count + 1))))
		return (NULL);
	i = 0;
	while (piece[i])
	{
		if (!(new_p[i] = (char*)malloc(sizeof(char) * 20)))
			return (NULL);
		if (piece[i][0] == '#')
			new_p[i] = piece[i];
		else if (piece[i][0] != '#')
			new_p[i] = moveleft(moveup(piece[i]));
		i++;
	}
	return (new_p);
}
