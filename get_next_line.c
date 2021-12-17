/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:54:13 by ccariou           #+#    #+#             */
/*   Updated: 2021/12/16 19:57:42 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_copyline(char **result, char **line)
{
	int		index;
	char	*tmp;

	index = 0;
	while (*result[index])
		index++;
	printf("ret = %i\n", index);
	if (*result[index] == '\n')
	{
		*line = ft_strsub(*result, 0, index);
		tmp = ft_strdup(&(*result)[index + 1]);
		ft_memdel((void **)&result);
		*result = tmp;
		if ((*result)[0] == '\0')
			ft_strdel(result);
	}
	else
	{
		*line = ft_strdup(*result);
		ft_strdel(result);
	}
	return (1);
}

int	ft_return(char **result, char **line, size_t ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && !result[fd])
		return (0);
	return(ft_copyline(&result[fd], line));
}

int	get_next_line(const int fd, char **line)
{
	size_t		ret;
	static char	*result[FD_SIZE];
	char		*tmp;
	char		buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (!result[fd])
		result[fd] = ft_strnew(0);
	ret = 1;
	while (!ft_strchr(result[fd], '\n') && ret > 0)
	{
		ret = read(fd, buf, BUFF_SIZE);
		printf("ret%zu\n", ret);
		buf[ret] = '\0';
		tmp = ft_strjoin(result[fd], buf);
		printf("%s\n", tmp);
		ft_memdel((void **)&result);
		result[fd] = tmp;
		printf("%s\n", *result);
	}
	return(ft_return(result, line, ret, fd));
}
