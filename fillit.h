/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:40:00 by dysotoma          #+#    #+#             */
/*   Updated: 2018/03/19 14:40:18 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>

int				validate(char *file);
int				place_piece(char **map, char *piece, int *board, int i);
void			remove_piece(char **map, char *alpha, int dimension, int i);
int				solve(char **map, char **pieces, int *board, int i);
int				been_placed(char *str, int i, int flag);
int				can_place(char **map, char *piece, int *dimension);
char			**normalize(char **piece);

#endif
