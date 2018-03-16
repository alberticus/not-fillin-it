/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsai <atsai@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:04:56 by atsai             #+#    #+#             */
/*   Updated: 2018/03/16 15:56:15 by atsai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*fileRead(char *path)
{
	int bytes;
	int filedesc;
	char buffer[547]; //file should not be bigger than 545 bytes

	filedesc = open(path, O_RDONLY);
	if (filedesc == -1) // if path is invalid, open returns -1
		return (NULL);
	bytes = read(filedesc, buffer, 547); // read that stuff
	if (bytes == 546) // if it actually reads past 545, file is invalid. reject it.
		return (NULL);
	buffer[bytes] = '\0'; // null terminate the buffer
	return (ft_strdup(buffer)); // make a permanent copy of the buffer and return the result
}
