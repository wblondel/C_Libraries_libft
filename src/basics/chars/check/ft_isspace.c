/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isspace.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:43 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/30 02:43:51 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "basics/chars.h"

/*
** Checks whether c is a white-space character.
*/

int		ft_isspace(int c)
{
	return (ft_isblank(c) || (c >= 10 && c <= 13));
}
