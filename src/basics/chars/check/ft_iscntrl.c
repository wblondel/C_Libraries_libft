/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_iscntrl.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:41 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/30 02:41:21 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/basics/chars.h"

/*
** Checks whether c is a control character.
*/

int		ft_iscntrl(int c)
{
	return (!ft_isprint(c));
}
