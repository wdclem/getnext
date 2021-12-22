/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:20:19 by ccariou           #+#    #+#             */
/*   Updated: 2021/12/22 10:43:06 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	set_copy(char *copy[], char *temp, const int fd)
{
	ft_strdel(&copy[fd]);
	copy[fd] = ft_strdup(temp);
	ft_strdel(&temp);
}

int	read_file(char *copy[], const int fd, char *temp)
{
	char	buf[BUFF_SIZE + 1];
	int		bytes;

	bytes = read(fd, buf, BUFF_SIZE);
	if (bytes == 0)
		return (0);
	buf[bytes] = '\0';
	temp = ft_strjoin(copy[fd], buf);
	set_copy(copy, temp, fd);
	return (1);
}

static int ft_return_last(char **result, char **line, const int fd)
{
	*line = ft_strdup(result[fd]);
	ft_strdel(&result[fd]);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	size_t		ret;
	static char	*result[FD_SIZE];
	char		*tmp;
	char		buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	tmp = NULL;
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	while(ret > 0)
	{
		read_file(result, fd, tmp);
	}
	if (ft_strlen(result[fd]) != 0)
	{
		if (!(ft_strchr(result[fd], '\n')))
			return (single_line(result, &*line, fd));
		*ptr = '\0';
		temp = ft_strdup(ptr + 1);
		*line = ft_strdup(result[fd]);
		set_copy(result, temp, fd);
	}
	else
		return (0);
	return (1);
}
