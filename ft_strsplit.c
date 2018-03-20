/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:39:53 by dysotoma          #+#    #+#             */
/*   Updated: 2018/03/05 12:39:58 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define INIT size_t i; size_t index; size_t f; char **str

static int		ft_wc(const char *str, char c)
{
	int	f;

	f = 0;
	while (*str)
	{
		if (*str != c && *str)
			if ((*(str + 1) == c && *(str + 2) == c) || !*(str + 1))
				f++;
		str++;
	}
	return (f);
}

char			**ft_strsplit(char const *s, char c)
{
	INIT;
	i = 0;
	index = 0;
	if (!(str = (char **)ft_memalloc(sizeof(char *) * (ft_wc(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i + 1] == c)
			i++;
		if (!s[i])
			break ;
		f = 0;
		while ((s[i + f] != c && s[i + f])
			|| (s[i + f + 1] != c && s[i + f] == c))
			f++;
		if (!(str[index] = ft_strsub(s, i, f)))
			return (NULL);
		i = i + f;
		index++;
	}
	str[index] = 0;
	return (str);
}
