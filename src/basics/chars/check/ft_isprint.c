/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isprint.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:42 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/30 02:42:58 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "basics/chars.h"

/*
** Checks whether c is a printable character.
*/

int		ft_isprint(int c)
{
	return (ft_isgraph(c) || c == 32);
}
