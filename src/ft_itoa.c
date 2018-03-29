/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:43 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:43 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*
** The itoa() function converts the integer pointed to
** by int to str representation.
*/

char	*ft_itoa(int n)
{
	char			*s;
	size_t			len;
	unsigned int	x;
	int				negative;

	negative = n < 0;
	if (negative)
		x = 0 - (unsigned)n;
	else
		x = (unsigned)n;
	len = ft_intlen(x) + negative;
	if (!(s = ft_strnew(len)))
		return (NULL);
	if (negative)
		s[0] = '-';
	s[--len] = (x % 10) + '0';
	x /= 10;
	while (x)
	{
		s[--len] = (x % 10) + '0';
		x /= 10;
	}
	return (s);
}
