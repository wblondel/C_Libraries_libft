/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   memory.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/30 01:59:37 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/30 02:45:40 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_MEMORY_H
# define LIBFT_MEMORY_H

# include <stddef.h>
# include "basics/booleans.h"

void	*ft_memalloc(size_t size);

void	ft_memdel(void **ap);

void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	ft_bzero(void *s, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_swap(void *x, void *y, size_t bytes);
void	ft_swap_c(char *a, char *b);
void	ft_swap_i(int *a, int *b);

#endif
