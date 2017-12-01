/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isascii.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:41 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:41 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
** Tests for an ASCII character, which is any character between
** 0 and decimal 128 inclusive.
*/

int		ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}
