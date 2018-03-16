/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsai <atsai@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:56:26 by atsai             #+#    #+#             */
/*   Updated: 2018/03/16 15:56:49 by atsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
int linesizefinder(char *input)
{
	int characters;

	characters = 0;
	while (input[characters] != '\n')
		characters++;
	return (characters);
}

int     connectionfinder(char *input, int index, int line, int linesize)
{
	int count;

	count = 0;
	if (line == 0)
	{
		if (input[index + 1] == '#')
			count++;
		if (input[index - 1] == '#')
			count++;
		if (input[index + linesize] == '#')
			count++;
	}
	if (line == linesize)
	{
		if (input[index + 1] == '#')
			count++;
		if (input[index - 1] == '#')
			count++;
		if (input[index - linesize] == '#')
			count++;
	}
	if (line != 0 && line != linesize)
	{
		if (input[index + 1] == '#')
			count++;
		if (input[index - 1] == '#')
			count++;
		if (input[index + linesize] == '#')
			count++;
		if (input[index - linesize] == '#')
			count++;
	}
	return (count);
}
int    validates(char *fileinput)
{
	int index;
	int lines;
	int poundsigns;
	int connections;
	int linesize;

	index = 0;
	lines = 0;
	poundsigns = 0;
	connections = 0;
	linesize = linesizefinder(fileinput);
	while (fileinput[index])
	{
		if (fileinput[index] != '.' && fileinput[index] != '#' && fileinput[index] != '\n')
			return (0);
		if (fileinput[index] == '\n')
		{
			if (fileinput[index + 1] == '\n' && fileinput[index + 2] == '\n')
				return (0);
			lines++;
		}
		if (fileinput[index] == '#')
		{
			connections = connectionfinder(fileinput, index, lines, linesize) + connections;
			poundsigns++;
		}
		if (lines == linesize)
		{
			if (((fileinput[index + 1] != '\n') && (fileinput[index + 1] != '\0')) || (poundsigns != 4) || (connections < 4))
				return (0);
			poundsigns = 0;
			lines = 0;
			connections = 0;
		}
		index++;
	}
	return (1);
}
