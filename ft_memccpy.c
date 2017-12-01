/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:46 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:46 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dp;
	unsigned const char	*sp;

	dp = (unsigned char*)dst;
	sp = (unsigned const char*)src;
	if (n)
	{
		while (n--)
		{
			if ((*dp++ = *sp++) == (unsigned char)c)
				return (dp);
		}
	}
	return (0);
}
