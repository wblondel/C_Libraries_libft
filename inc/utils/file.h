/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   file.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wblondel <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/30 07:24:29 by wblondel     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/30 07:26:02 by wblondel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_FILE_H
# define LIBFT_FILE_H

# include "containers/list.h"

# define BUFF_SIZE 4096

int		ft_readline(int const fd, char **line);

#endif
