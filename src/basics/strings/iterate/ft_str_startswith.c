/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_startswith.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:50 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:50 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "basics/strings.h"

int		ft_str_startswith(char *s1, char *s2)
{
	int len;

	len = ft_strlen(s2);
	return (ft_strncmp(s1, s2, len) == 0);
}
