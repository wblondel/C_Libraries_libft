/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:51 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:51 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/basics/strings.h"
#include "libft/basics/memory.h"

/*
** The strdup() function allocates sufficient memory for a copy of
** the string s1, does the copy, and returns a pointer to it.
** If insufficient memory is available, NULL is returned.
*/

char	*ft_strdup(const char *s1)
{
	int		s1_l;
	char	*dest;

	s1_l = ft_strlen(s1) + 1;
	dest = (char*)malloc(s1_l);
	if (dest == (char*)0)
		return (char*)0;
	return (char*)ft_memcpy(dest, s1, s1_l);
}
