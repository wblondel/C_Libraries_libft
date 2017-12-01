/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:55 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:55 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(str);
	while (i < size / 2)
	{
		ft_swap_c(&str[i], &str[size - 1 - i]);
		i++;
	}
}
