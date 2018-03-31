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
#define MAP_AND_PIECE char **map_pieces; char **norm_piece; char **map
#define BOARD board[0] = 0; board[1] = 0; board[2] = 2

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
		if (!(map[i] = (char*)malloc(sizeof(char) * 16)))
			return (NULL);
		map[i] = ft_memset(map[i], '.', 15);
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

static void		print_map(char **map, int border)
{
	int y;
	int x;

	y = 0;
	while (y < border)
	{
		x = 0;
		while (x < border)
			write(1, &map[y][x++], 1);
		write(1, "\n", 1);
		y++;
	}
}

int				main(int ac, char **av)
{
	int		board[3];
	int		i;

	MAP_AND_PIECE;
	BOARD;
	i = 0;
	if (ac != 2)
	{
		ft_putendl("Please put in one valid .txt file!");
		return (0);
	}
	if ((!(validate(fileread(av[1])))))
	{
		ft_putendl("error");
		return (0);
	}
	map_pieces = ft_strsplit_double_char(fileread(av[1]), '\n');
	norm_piece = normalize(map_pieces);
	map = make_map();
	while (!solve(map, norm_piece, board, i))
		board[2]++;
	free_map(norm_piece);
	print_map(map, board[2]);
	free_map(map);
	return (0);
}
