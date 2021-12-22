/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clabone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:21:34 by ccariou           #+#    #+#             */
/*   Updated: 2021/12/21 22:03:53 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

void	set_copy(char *copy[], char *temp, const int fd)
{
	ft_strdel(&copy[fd]);
	copy[fd] = ft_strdup(temp);
	ft_strdel(&temp);
}
 
int		read_file(char *copy[], const int fd, char *temp)
{
	char	buf[BUFF_SIZE + 1];
	int		bytes;
 
	if ((bytes = read(fd, buf, BUFF_SIZE)) == 0)
		return (0);
	buf[bytes] = '\0';
	temp = ft_strjoin(copy[fd], buf);
	set_copy(copy, temp, fd);
	return (1);
}
 
int		single_line(char *copy[], char **line, const int fd)
{
	*line = ft_strdup(copy[fd]);
	ft_strclr(copy[fd]);
	return (1);
}
 
int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*copy[1024];
	char		*temp;
	char		*ptr;
 
	temp = NULL;
	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	if (!copy[fd])
		copy[fd] = ft_strnew(0);
	while ((ptr = ft_strchr(copy[fd], '\n')) == NULL)
		if ((read_file(copy, fd, temp)) == 0)
			break ;
	if (ft_strlen(copy[fd]) != 0)
	{
		if (!(ft_strchr(copy[fd], '\n')))
			return (single_line(copy, &*line, fd));
		*ptr = '\0';
		temp = ft_strdup(ptr + 1);
		*line = ft_strdup(copy[fd]);
		set_copy(copy, temp, fd);
	}
	else
		return (0);
	return (1);
}
