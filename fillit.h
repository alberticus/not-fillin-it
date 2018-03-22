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

typedef struct	s_tetri_data
{
}				t_tetri_data;

int				validate(char *file);
char			**set_map(char *map);
char			**ft_strsplit(char const *s, char c);
void			ft_bzero(void *str, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memalloc(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strnew(size_t size);
void			ft_putendl(char const *s);
char			*ft_strstr(const char *str, const char *to_find);
char			**make_pieces(char *map);

#endif
