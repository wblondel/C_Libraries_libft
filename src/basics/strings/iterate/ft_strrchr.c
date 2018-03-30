/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:55 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:55 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = NULL;
	if (*s == (char)c)
		ret = (char *)s;
	while (*s++)
		if (*s == (char)c)
			ret = (char *)s;
	return (ret);
}
