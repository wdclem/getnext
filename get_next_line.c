/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clabone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:21:34 by ccariou           #+#    #+#             */
/*   Updated: 2021/12/22 12:52:27 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

static int	set_dup(char **dup, char *tmp)
{
	ft_strdel(dup);
	*dup = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (1);
}

static int	ft_read(char **dup, const int fd, char *tmp)
{
	char	buf[BUFF_SIZE + 1];
	int		bytes;

	bytes = read(fd, buf, BUFF_SIZE);
	if (bytes == 0)
		return (0);
	buf[bytes] = '\0';
	tmp = ft_strjoin(dup[fd], buf);
	set_dup(&dup[fd], tmp);
	return (1);
}

static int	ft_single_line(char **dup, char **line)
{
	*line = ft_strdup(*dup);
	ft_strclr(*dup);
	return (1);
}

static int	ft_outuput(char **dup, char **line, char *tmp, char *ptr)
{
	if (!(ft_strchr(*dup, '\n')))
		return (ft_single_line(dup, line));
	tmp = ft_strdup(ptr + 1);
	*line = ft_strsub(*dup, 0, (ptr - *dup));
	return (set_dup(dup, tmp));
}

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*dup[FD_SIZE];
	char		*tmp;
	char		*ptr;

	tmp = NULL;
	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	if (!dup[fd])
		dup[fd] = ft_strnew(0);
	ptr = ft_strchr(dup[fd], '\n');
	while (ptr == NULL)
	{
		if ((ft_read(dup, fd, tmp)) == 0)
			break ;
		ptr = ft_strchr(dup[fd], '\n');
	}
	if (ft_strlen(dup[fd]) != 0)
		return (ft_outuput (&dup[fd], line, tmp, ptr));
	return (0);
}
