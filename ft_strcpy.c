/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:51 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:51 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
** Copies the string src to dst (including the terminating '\0' character.
** Behaviour is undefined if they overlap.
*/

char	*ft_strcpy(char *dst, const char *src)
{
	char *first;

	first = dst;
	while ((*dst++ = *src++))
		;
	return (first);
}
