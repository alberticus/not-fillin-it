/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsai <atsai@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:15:48 by atsai             #+#    #+#             */
/*   Updated: 2018/03/21 13:41:18 by atsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char **convert(char *piece, int index, int x, int y)
{
	char** converted;

	if (!(converted = (char**)malloc(sizeof(char) * 25)))
		return (NULL);
	ft_memset(converted, 0, sizeof(converted[0][0]) * 5 * 5 );
	while (y < 5)
	{
		while (x < 5)
		{
			converted[x][y] = piece[index];
			x++;
			index++;
		}
		x = 0;
		y++;
	}
	return (converted);
}

void normalize_array(char ***shapearray, int totalpieces)
{
	int index;
	
	index = 0;
	while (index < totalpieces)
	{
		normalize_piece(shapearray[index]);
		index++;
	}
}

void normalize_piece(char **piece)
{
	int x;
	int y;
	int startx;
	int starty;
	
	x = 0;
	y = 0;
	startx = 4;
	starty = 4;
	while (x < 4)
	{
		while (y < 4)
		{
			if (piece[x][y] == '#')
			{
				if (x < startx)
					startx = x;
				if (y < starty)
					starty = y;
			}
			y++;
		}
		x++;
	}
	x = 0;
	y = 0;
	while (x < startx)
	{
		moveleft(piece);
		x++;
	}
	while (y < starty)
	{
		moveup(piece);
		y++;
	}
}
