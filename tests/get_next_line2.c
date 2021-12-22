/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:11:20 by ccariou           #+#    #+#             */
/*   Updated: 2021/12/21 17:32:07 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*char	**ft_read(const fd)
{
	size_t		ret;

}*/
static int	ft_copyline(char **result, char **line, const int fd)
{
	int		index;
	char	*tmp;

	index = 0;
	while (result[fd][index] != '\n' && result[fd][index]) 
		index++;
	if (result[fd][index] == '\n')
	{
		*line = ft_strsub(result[fd], 0, index);
		tmp = ft_strdup(result[fd] + (index + 1));
		free(result[fd]);
		result[fd] = tmp;
		if (result[fd][0] == '\0')
			ft_strdel(&result[fd]);
	}
	return (1);
}
static int ft_return_last(char **result, char **line, const int fd)
{
	*line = ft_strdup(result[fd]);
	ft_strdel(&result[fd]);
	return (1);
}

/*static int	ft_return(char **result, char **line, size_t ret, int fd)
{
	if (ret == 0 && !result[fd])
		return (0);
	else
		return(ft_copyline(result, line, fd));
}
*/
/*
char	*ft_read(const int fd , size_t ret, char buf[ret])
{
	static char	*result[FD_SIZE];
	char		*tmp;

	while(ret > 0)
	{
		buf[ret] = '\0';
		if (!result[fd] && ret > 0)
			result[fd] = ft_strnew(0);
		tmp = ft_strjoin(result[fd], buf);
		ft_memdel((void **)&result[fd]);
		result[fd] = tmp;
		printf("result %s\n", result[fd]);
		ret = read(fd, buf, BUFF_SIZE);
	}
	printf("result %s\n", result[fd]);
	return (result[fd]);
}
*/
int	get_next_line(const int fd, char **line)
{
	size_t		ret;
	static char	*result[FD_SIZE];
	char		*tmp;
	char		buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (ft_strchr (result[fd], '\n'))
		return(ft_copyline(result, line, fd));
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	while(ret > 0)
	{
		if (!result[fd] && ret > 0)
			result[fd] = ft_strnew(0);
		tmp = ft_strjoin(result[fd], buf);
		ft_strdel(&result[fd]);
		result[fd] = tmp;
		if (ft_strchr (result[fd], '\n'))
			return(ft_copyline(result, line, fd));
		else
			return(ft_return_last(result, line, fd));
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
	}
	if (ret == 0 && !result[fd])
		return (0);
	else
		return (ret);
}
	/*
	if (ret < 0)
		return (-1);
	else if (ret == 0 && !result[fd])
		return (0);
	index = 0;
	while (result[fd][index] != '\n' && result[fd][index] != '\0')
		index++;
	printf(" je suis sortir encore\n");
	if (result[fd][index] == '\n')
	{
		printf(" je suis sortir dans le if gros loulou\n");
		*line = ft_strsub(result[fd], 0, index);
		tmp = ft_strdup(result[fd] + (index + 1));
		ft_memdel((void **)&result);
		result[fd] = tmp;
	}
	else
	{
		*line = ft_strdup(result[fd]);
		ft_memdel((void **)&result);
	}
	printf("%s\n", tmp);
	return (1);
}*/

/*int	main()
{
	int		fd;
	int		retget;
	char	*tmp;
	char	**line;
	int		n = 1;

	line = &tmp;
	//fd = open("h.txt", O_RDONLY);
	//get_next_line(fd, &line);
	//printf("retget = %i\n", retget);
	//while((get_next_line(fd, &line) > 0))
	//	printf("%s\n", line);
	//get_next_line(fd, &line);
	//printf("%s\n", line);
	fd = open("gnl7_3.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	//printf("Two lines with newline:\n");
	while (1)
	{
		retget = get_next_line(fd, line);
		if (retget <= 0)
			break;
		printf("%s<- end of line %d\n", *line, n);
		free(*line);
		n++;
	}
	close (fd);
	//system("leaks a.out");
	return(0);
}*/
