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

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

int				validate(char *file);
char			**ft_strsplit(char const *s, char c);
void			ft_bzero(void *str, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memalloc(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strnew(size_t size);
void			ft_putendl(char const *s);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strdup(const char *src);
size_t			ft_strlen(const char *str);
char			**make_pieces(char *map);
int				place_piece(char **map, char *piece, int *board, int i);
void			remove_piece(char **map, char *alpha, int dimension, int i);
int				solve(char **map, char **pieces, int *board, int i);
int				been_placed(char *str, int i, int flag);
int				can_place(char **map, char *piece, int dimension);

#endif
