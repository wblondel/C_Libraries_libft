/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:56 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:56 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*hay;
	char	*haybegin;
	char	*nee;

	hay = (char*)haystack;
	if (!*needle)
		return (hay);
	while (*hay)
	{
		haybegin = hay;
		nee = (char*)needle;
		while (*hay && *nee && *hay == *nee)
		{
			hay++;
			nee++;
		}
		if (!*nee)
			return (haybegin);
		hay = haybegin + 1;
	}
	return (0);
}
