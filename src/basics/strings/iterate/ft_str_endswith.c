/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_endswith.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:49 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:49 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "basics/strings.h"

int		ft_str_endswith(char *s1, char *s2)
{
	int len1;
	int len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len2 > len1)
		return (0);
	return (ft_strcmp(s1 + (len1 - len2), s2) == 0);
}
