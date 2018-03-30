/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:55 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:55 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	char	*haybegin;
	char	*nee;
	size_t	plen;

	hay = (char*)haystack;
	plen = len;
	if (!*needle)
		return (hay);
	while (*hay && plen)
	{
		haybegin = hay;
		nee = (char*)needle;
		while (*hay && *nee && *hay == *nee && plen--)
		{
			hay++;
			nee++;
		}
		if (!*nee)
			return (haybegin);
		hay = haybegin + 1;
		len--;
		plen = len;
	}
	return (0);
}
