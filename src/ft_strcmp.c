/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:51 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:51 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *ps1;
	unsigned char *ps2;

	ps1 = (unsigned char*)s1;
	ps2 = (unsigned char*)s2;
	while (*ps1++ == *ps2++)
		if (*ps1 == '\0' && *ps2 == '\0')
			return (0);
	return (*--ps1 - *--ps2);
}
