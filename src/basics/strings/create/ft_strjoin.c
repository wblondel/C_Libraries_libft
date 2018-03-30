/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:52 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:52 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "basics/strings.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *res;

	res = NULL;
	if (s1 && s2)
	{
		res = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (res)
		{
			ft_strcpy(res, (char*)s1);
			ft_strcat(res, (char*)s2);
		}
	}
	return (res);
}
