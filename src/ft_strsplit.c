/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 10:20:56 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 10:20:56 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_word(const char *str, char c, int *i)
{
	char	*s;
	int		k;

	s = (char*)malloc(ft_strlen(str) * sizeof(s));
	if (!s)
		return (NULL);
	k = 0;
	while (str[*i] != c && str[*i])
	{
		s[k] = str[*i];
		k++;
		*i += 1;
	}
	s[k] = '\0';
	while (str[*i] == c && str[*i])
		*i += 1;
	return (s);
}

char			**ft_strsplit(const char *s, char c)
{
	int		i;
	int		j;
	int		wrd;
	char	**src;

	i = 0;
	j = 0;
	src = NULL;
	if (s)
	{
		wrd = ft_strcountwords(s, c);
		src = (char **)malloc(sizeof(src) * (wrd + 2));
		if (src)
		{
			while (s[i] == c && s[i])
				i++;
			while (j < wrd && s[i])
			{
				src[j] = ft_word(s, c, &i);
				j++;
			}
			src[j] = NULL;
		}
	}
	return (src);
}
