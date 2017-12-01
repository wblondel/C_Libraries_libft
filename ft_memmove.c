/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:47 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:47 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp;
	const char	*s;

	tmp = dst;
	s = src;
	if (src == dst)
		return (dst);
	if (src >= dst)
		ft_memcpy(tmp, s, len);
	else
	{
		s += len;
		tmp += len;
		while (len--)
			*--tmp = *--s;
	}
	return (dst);
}
