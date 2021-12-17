/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:11:20 by ccariou           #+#    #+#             */
/*   Updated: 2021/12/17 17:23:25 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

#define BUFF_SIZE 10
#define FD_SIZE 26

/*char	**ft_read(const fd)
{
	size_t		ret;

}*/
int	ft_copyline(char **result, char **line, const int fd)
{
	int		index;
	char	*tmp;

	printf("toujours des mechants monsieurs\n");
	index = 0;
	while (result[fd][index] != '\n' && result[fd][index] /*!= '\0'*/) 
		index++;
	printf("index = %i\n", index);
	if (result[fd][index] == '\n')
	{
		*line = ft_strsub(result[fd], 0, index);
		tmp = ft_strdup(result[fd] + (index + 1));
		//ft_memdel((void **)&result);
		free(result[fd]);
		result[fd] = tmp;
		printf("Salaud, tu as un gros loulou\n");
		if (result[fd][0] == '\0')
			ft_freearray(result, fd);
			printf("result = %s\n", result[fd]);
	}
	else
	{
		*line = ft_strdup(result[fd]);
		//free(result[fd]);
		//ft_freearray(result, fd);
		ft_strdel(result);
		printf("result gros loulou= %s\n", result[fd]);
		//ft_memdel((void **)&result);
	}
	printf("result gros = %s\n", result[fd]);
	return (1);
}

int	ft_return(char **result, char **line, size_t ret, int fd)
{
	printf("result = %s\n", result[fd]);
	if (ret < 0)
		return (-1);
	else if (ret == 0 && !result[fd])
		return (0);
	printf("j'aime les retours \n");
	return (ft_copyline(result, line, fd));
}

/*
char	**ft_read(const int fd)
{
	static char	*result[FD_SIZE];
	char		*tmp;
	char		buf[BUFF_SIZE + 1];
	size_t		ret;

	ret = 1;
	while(!ft_strchr(result[fd], '\n') && ret > 0)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		tmp = ft_strjoin(result[fd], buf);
		ft_memdel((void **)&result);
		result[fd] = tmp;
	}
	return (result[fd]);
}
*/

int	get_next_line(const int fd, char **line)
{
	size_t		ret;
	static char	*result[FD_SIZE];
	char		*tmp;
	char		buf[BUFF_SIZE + 1];

	if (result[fd] == NULL)
		result[fd] = ft_strnew(0);
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	ret = 1;
	while(!ft_strchr(result[fd], '\n') && ret > 0)
	{
		if (result[fd] == NULL && ret > 0)
			result[fd] = ft_strnew(0);
		ret = read(fd, buf, BUFF_SIZE);
		printf("ret = %zu\n", ret);
		buf[ret] = '\0';
		tmp = ft_strjoin(result[fd], buf);
		printf("temp = %s\n", tmp);
		ft_memdel((void **)&result);
		result[fd] = tmp;
		printf("result = %s\n", result[fd]);
	}
	printf(" je suis sortir \n");
	return(ft_return(result, line, ret, fd));
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
