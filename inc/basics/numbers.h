/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   numbers.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/30 02:04:58 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/30 02:10:19 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_NUMBERS_H
# define LIBFT_NUMBERS_H

# include <stddef.h>

int		ft_atoi(const char *str);
char	*ft_itoa(int n);

int		ft_intlen(int n);

void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);

#endif
