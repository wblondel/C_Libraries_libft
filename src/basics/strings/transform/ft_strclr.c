/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strclr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:50 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:50 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/basics/memory.h"
#include "libft/basics/strings.h"

void	ft_strclr(char *s)
{
	if (s)
		ft_memset(s, '\0', ft_strlen(s));
}
