/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ispunct.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:43 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/30 02:43:23 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "basics/chars.h"

/*
** Checks whether c is a punctuation character.
*/

int		ft_ispunct(int c)
{
	return (ft_isgraph(c) && !ft_isalnum(c));
}
