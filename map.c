/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:21:36 by dysotoma          #+#    #+#             */
/*   Updated: 2018/03/19 17:21:38 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void free_map(char **map)
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

char		**set_map(void)
{
	char** map;

	if (!(map = (char**)malloc(sizeof(map[0][0]) * 15 * 15)))
		return (NULL);
	return (ft_memset(map, '.', sizeof(map[0][0]) * 15 * 15));
}
