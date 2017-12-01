/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isgraph.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:42 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:42 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
** Checks whether c is a character with graphical representation.
*/

int		ft_isgraph(int c)
{
	return (c >= 33 && c <= 126);
}
