/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:53 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:53 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stddef.h>

/*
** Returns the length of a string
*/

size_t	ft_strlen(const char *s)
{
	int l;

	l = 0;
	while (*s++)
		l++;
	return (l);
}
