/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strndup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 07:00:18 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 07:02:57 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "basics/memory.h"
#include "basics/strings.h"

char			*ft_strndup(const char *str, size_t len)
{
	char *ret;

	ret = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	ft_strncpy(ret, str, len);
	ret[len] = '\0';
	return (ret);
}
