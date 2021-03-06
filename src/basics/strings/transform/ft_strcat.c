/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:50 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:50 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	char *first;

	first = s1;
	while (*s1)
		s1++;
	while (*s2)
		*s1++ = *s2++;
	*s1++ = '\0';
	return (first);
}
