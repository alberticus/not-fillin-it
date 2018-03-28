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


void	normalize(char *piece)
{
	moveup(piece);
	moveleft(piece);
}

void	moveup(char *piece)
{
	int index;
	char newpiece[20];
	int unwantedrows;
	int copyindex;

	index = 0;
	unwantedrows = 0;
	while (piece[index] != '#')
	{
		index++;
		if (piece[index] == '\n')
			unwantedrows++;
	}
	if (unwantedrows == 1)
		copyindex = 5;
	if (unwantedrows == 2)
		copyindex = 10;
	if (unwantedrows == 3)
		copyindex = 15;
	index = 0;
	while (piece[copyindex])
	{
		newpiece[index] = piece[copyindex];
		index++;
		copyindex++;
	}
	newpiece[index] = '\0';
}


