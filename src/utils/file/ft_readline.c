/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 05:44:17 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/16 22:41:23 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft/basics/strings.h"
#include "libft/containers/list.h"
#include "libft/utils/file.h"

/*
** If there is already something in tmp, we find back the fd associated with
** the string.
** If not, we create a new node with an empty string and add it to the list.
*/

static t_list		*ft_findfd(t_list **begin, int fd)
{
	t_list *tmp;

	tmp = *begin;
	if (tmp)
	{
		while (tmp)
		{
			if (fd == (int)tmp->content_size)
				return (tmp);
			tmp = tmp->next;
		}
	}
	tmp = ft_lstnew("\0", 1);
	tmp->content_size = fd;
	ft_lstadd(begin, tmp);
	return (tmp);
}

/*
** This function joins two strings (max n characters) and free the result.
*/

static char			*ft_joinandfree(char *tmp, char *buf, int ret)
{
	char	*l;

	l = tmp;
	tmp = ft_strnjoin(tmp, buf, ret);
	free(l);
	return (tmp);
}

/*
** 1) If file reading is OK, we create the first node of our linked list.
** 2) We then join everything that we read until we find a \n in our content.
** Everything we join is saved into list->content.
** 3) We then go through what we have read to only copy to our linked list
** the first line.
** 4) We then increment ret to pass the \n ()
** 5) We then use the variable l to temporary hold what is currently in
** list->content.
** 6) We allocate the memory from our current position in list->content
** (variable ret) and we free what's inside l from our memory.
** 7) We then return 1 at \n or at \0, or 0 if nothing was read.
*/

int					ft_readline(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static t_list	*list = NULL;
	t_list			*begin;
	char			*l;

	if (line == NULL || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	begin = list;
	list = ft_findfd(&begin, fd);
	while (!ft_strchr(list->content, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
		list->content = ft_joinandfree(list->content, buf, ret);
	ret = 0;
	while (((char *)list->content)[ret] && ((char *)list->content)[ret] != '\n')
		++ret;
	*line = ft_strndup(list->content, ret);
	if (((char *)list->content)[ret] == '\n')
		++ret;
	l = list->content;
	list->content = ft_strdup(list->content + ret);
	free(l);
	list = begin;
	return (ret ? 1 : 0);
}
