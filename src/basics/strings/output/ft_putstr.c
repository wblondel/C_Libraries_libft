/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:49 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:49 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/basics/chars.h"

void	ft_putstr(char const *s)
{
	if (s != 0)
	{
		while (*s)
		{
			ft_putchar(*s);
			s++;
		}
	}
}
