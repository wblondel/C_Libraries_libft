/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:56 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:56 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/basics/strings.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *res;
	char *ps;

	res = NULL;
	if (s)
	{
		res = ft_strnew(len);
		ps = (char *)s;
		if (res)
		{
			ps += start;
			ft_strncpy(res, ps, len);
		}
	}
	return (res);
}
