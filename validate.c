/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.ct                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsai <atsai@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:56:26 by atsai             #+#    #+#             */
/*   Updated: 2018/03/16 15:56:49 by atsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#define SET_PIECE int i = 0; int lines = 0; int connect = 0; int hash = 0

static int		reset(int *lines, int *connect, int *hash)
{
	*lines = 0;
	*connect = 0;
	*hash = 0;
	return (1);
}

/*
**	used to make sure each tetrimino has a valid number of connections
*/

static int		cfinder(char *input, int i, int line, int linesize)
{
	int count;

	count = 0;
	if (line != linesize)
	{
		if (input[i + 1] == '#')
			count++;
		if (input[i + linesize] == '#')
			count++;
	}
	if (line == linesize - 1)
	{
		if (input[i + 1] == '#')
			count++;
	}
	return (count);
}

/*
**	iterates through the full tetrimino string list and pass it in chunks to
**	cfind for validation
*/

static int		valid_check(char *file)
{
	SET_PIECE;
	while (file[i])
	{
		if (file[i] != '.' && file[i] != '#' && file[i] != '\n')
			return (0);
		if (file[i] == '\n')
		{
			if (file[i + 1] == '\n' && file[i + 2] == '\n')
				return (0);
			lines++;
		}
		if (file[i] == '#')
		{
			connect = cfinder(file, i, lines, 5) + connect;
			hash++;
		}
		if (lines == 4)
			if ((file[i + 1] != '\n' && file[i + 1]) || hash != 4 ||
				connect < 3)
				return (0);
		if (file[i] == '\n' && file[i + 1] == '\n')
			i += reset(&lines, &connect, &hash);
		i++;
	}
	return (1);
}

/*
**	checks to make sure each tetrimino is the proper length
*/

static int		ft_ps(const char *str, char c)
{
	int	ct;
	int len;

	ct = 0;
	while (str[ct])
	{
		len = 0;
		if (str[ct] == c)
			ct++;
		while (len < 19)
			len++;
		if ((len != 19 && str[ct + len + 1] == c && str[ct + len] == c)
			|| (len != 19 && !(str[ct + len + 1]))
			|| (len == 19 && str[ct + len] != c && str[ct + len + 1] != c))
			return (0);
		else if ((str[ct + len + 1] == c && str[ct + len] == c)
				|| (str[ct + len] == c && !(str[ct + len + 1])))
			ct += len;
		ct++;
	}
	return (1);
}

int				validate(char *file)
{
	if (!*file)
		return (0);
	if (!(ft_ps(file, '\n')))
		return (0);
	if (valid_check(file))
		return (1);
	return (0);
}
