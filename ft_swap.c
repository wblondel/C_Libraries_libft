/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_swap.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:57 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:57 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *x, void *y, size_t bytes)
{
	void *tmp;

	tmp = malloc(bytes);
	ft_memcpy(tmp, x, bytes);
	ft_memcpy(x, y, bytes);
	ft_memcpy(y, tmp, bytes);
	free(tmp);
}
