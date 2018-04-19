/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   chars.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/30 01:33:38 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/30 02:40:44 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
** @file		chars.h
** @brief		C chars management functions
**
** Functions to test, transform and print the C native chars.
*/

#ifndef LIBFT_CHARS_H
# define LIBFT_CHARS_H

# include <stddef.h>
# include "libft/basics/booleans.h"

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isblank(int c);
int		ft_iscntrl(int c);
int		ft_isdigit(int c);
int		ft_isgraph(int c);
int		ft_islower(int c);
int		ft_isprint(int c);
int		ft_ispunct(int c);
int		ft_isspace(int c);
int		ft_isupper(int c);

void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);

int		ft_tolower(int c);
int		ft_toupper(int c);

#endif
