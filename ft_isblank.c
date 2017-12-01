/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isblank.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:41 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:41 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
** Checks whether c is a blank character (space or tab).
*/

int		ft_isblank(int c)
{
	return (c == 9 || c == 32);
}
