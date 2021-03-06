/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtoupper.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:56 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:56 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/basics/chars.h"

void	ft_strtoupper(char *s)
{
	while (*s != '\0')
	{
		if (ft_islower(*s))
			*s = ft_toupper(*s);
		s++;
	}
}
