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
#include "libft.h"

static void		free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static char		**make_map(void)
{
	int		i;
	char	**map;

	if (!(map = (char**)malloc(sizeof(char*) * 15 + 1)))
		return (NULL);
	i = 0;
	while (i < 15)
	{
		if (!(map[i] = ft_memset(map[i] = (char*)malloc(sizeof(char*) * 15 + 1) , '.', 15)))
			return (NULL);
		map[i][15] = '\0';
		i++;
	}
	return (map);
}

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
	char	**map_pieces;
	char	**map;
	int		board[2];
	int		i;

	i = 0;
	if (!(validate(fileread(av[1]))) && ac > 1)
		ft_putendl("Error: invalid option please use an appropriate .txt file");
	map_pieces = ft_strsplit_double_char(fileread(av[1]), '\n');
	map = make_map();
	solve(map, map_pieces, board, i);
	free_map(map_pieces);
	print_map(map);
	free_map(map);
	return (0);
}
