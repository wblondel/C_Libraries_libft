/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strings.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/30 02:10:34 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/30 03:01:06 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_STRINGS_H
# define LIBFT_STRINGS_H

# include <stddef.h>
# include "libft/basics/booleans.h"
# include "libft/containers/list.h"

char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strndup(const char *str, size_t len);
char	*ft_strnew(size_t size);
char	*ft_strnjoin(char const *s1, char const *s2, size_t len);
char	**ft_strsplit(const char *s, char c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s);

void	ft_strdel(char **as);

int		ft_str_endswith(char *s1, char *s2);
int		ft_str_startswith(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strcountwords(const char *str, char c);
int		ft_strequ(char const *s1, char const *s2);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *haystack, const char *needle);

void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putstr(char const *s);
void	ft_putstr_fd(char const *s, int fd);

char	*ft_strcat(char *s1, const char *s2);
void	ft_strclr(char *s);
char	*ft_strcpy(char *dst, const char *src);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strmerge(char *a, char *b);
char	*ft_strncat(char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t len);
void	ft_strrev(char *str);
void	ft_strtolower(char *s);
void	ft_strtoupper(char *s);

#endif
