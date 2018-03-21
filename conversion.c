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
