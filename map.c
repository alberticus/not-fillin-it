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
    free(map[i])
      i++;
  }
  free(map);
}

char		**make_map(char *map_str)
{
}

char		**set_map(char *map_str)
{

}