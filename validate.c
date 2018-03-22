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

static int		valid_check(char *file, int lines, int hash, int connect)
{
	int i;

	i = -1;
	while (file[++i])
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
		if (lines == 5)
			if (((file[i + 1] != '\n') && (file[i + 1]))
				|| (hash != 4) || (connect < 3))
				return (0);
	}
	return (1);
}

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

static int		ft_ps(const char *str, char c)
{
	int	ct;
	int len;

	ct = 0;
	while (str[ct])
	{
		if (str[ct] == c)
			ct++;
		len = 0;
		while (str[ct + len] != c)
			len++;
		if ((len != 20 && str[ct + len + 1] == c && str[ct + len] == c)
			|| len != 20 && !(str[ct + len + 1]))
			return (0);
		else if (str[ct + len + 1] == c && str[ct + len] == c)
			ct += len;
		ct++;
	}
	return (1);
}

int				validate(char *file)
{
	int i;
	int lines;
	int hash;
	int connect;

	i = 0;
	lines = 0;
	hash = 0;
	connect = 0;
	if (!(ft_ps(file, '\n')))
		return (0);
	if (valid_check(file, lines, hash, connect))
		return (1);
	return (0);
}
