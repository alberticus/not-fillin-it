/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsai <atsai@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:04:56 by atsai             #+#    #+#             */
/*   Updated: 2018/03/16 15:56:15 by atsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*fileread(char *path)
{
	int		bytes;
	int		filedesc;
	char	buffer[547];

	filedesc = open(path, O_RDONLY);
	if (filedesc == -1)
		return (NULL);
	bytes = read(filedesc, buffer, 547);
	if (bytes == 546)
		return (NULL);
	buffer[bytes] = '\0';
	return (ft_strdup(buffer));
}

static void		print_map(char **map)
{
	while (*map)
		ft_putendl(*map++);
}

int				main(int ac, char **av)
{
	char **map;

	if (!(validate(fileread(av[1]))))
		return ;// status / usage message
	map = set_map(fileread(av[1]));
	print_map(map);
}
