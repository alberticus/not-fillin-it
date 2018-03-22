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

char **convert(char *piece)
{
	char** converted;
	int index;
	int x;
	int y;

	index = 0;
	x = 0;
	y = 0;
	converted = (char**)malloc(sizeof(char) * 25);
	while (y < 5)
	{
		while (x < 5)
		{
			converted[x][y] = piece[index];
			if (x == 5)
				converted[x][y] = '\0';
			x++;
			index++;
		}
		x = 0;
		y++;
		if (y == 5)
		{
			while (x <= 5)
			{
				converted[x][y] = '\0';
				x++;
			}
		}
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
				
