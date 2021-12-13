/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:11:20 by ccariou           #+#    #+#             */
/*   Updated: 2021/12/13 17:34:27 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

#define BUF_SIZE 110


int	get_next_line(const int fd, char **line)
{
//	size_t		len;
	size_t		ret;
//	int			fill;
	static char	*result;
	char		*tmp;
	char		buf[BUF_SIZE + 1];

	//result == NULL ? result = ft_strnew(0) : 0;
	if (result == NULL)
		result = ft_strnew(0);
/* handle fd potential errors simplify to < 3 */
	//printf("fd = %d\n", fd);
	if (fd < 0 || !line || BUF_SIZE <= 0)
		return (-1);
	//printf("%s\n", result);
	//fill = read(fd, buf, BUF_SIZE);
	//if fill == o or == -1
	//printf("fill %i\n", fill);
	/* need an other condition for the loop to stop when finding \n ? or > 0 ? */
	while(!ft_strchr(result, '\n') && (ret = read(fd, buf, BUF_SIZE)) > 0)
	{
	//	printf("ret%zu\n", ret);
		buf[ret] = '\0';
		tmp = ft_strjoin(result, buf);
		/* bzero ? or memdel to make result 2d */
		ft_memdel((void **)&result);
		result = tmp;
		//printf("%s\n", result);
	}
	//printf("ret%zu\n", ret);
	/* if ret 0 line == complete result ? should it check for \n ? */
	if (ret == 0)
		*line = ft_strdup(result);
	/* if I want to print line by line need to find a trick for \n, I want line 
	 * to be == result if ret is not 0 but result == \n */
	int	index = 0;
	while (result[index] != '\n' && result[index] != '\0')
		index++;
	//printf("index = %i", index);
	if (ret > 0)
		*line = ft_strsub(result, 0, index);
	//printf("line len = %zu", ft_strlen(*line));
	//result = &result[index + 1];
	//tmp = &result[index + 1];
	if (ret > 0)
		tmp = ft_strdup(result + (index + 1));
	else
		tmp = ft_strdup(result + index);
	ft_memdel((void **)&result);
	result = tmp; 
	//free (tmp); ??
	/* if fill exist duplicate the content */
//	len = ft_strlen((char *) buf);
//	printf("%zu\n", len);
/*	while () 
	{
		strcpy((char *) buf, *line);
		for(int i = 0; i < len; i++)
		{
			line[i] = (char)buf[i];
	 	}
	}*/
		//printf("isfd %i", isfd);
		//*line = ft_strdup((char *)buf);
		//*line = ft_memcpy(&buf[0], 
		//printf("fill %i", fill);
	/* loop the read according to putsize, find a way to save it in line */
	/*while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';// set end of char at the end of the read ?
		*line = ft_memmalloc(ret);
		line = ft_strcpy(*line, buf);
		ft_putstr(buf);
	}
	*/
	/* to remember return value
	if (read)
		return (1);
	if (readcomplete)
		return (0);
	if (error)
		return (-1);
		*/
	printf("ret = %zu\n", ret);
	if (ret == 0)
		ft_memdel((void **)&result);
	return (ret == 0 ? 0 : 1);
}

int	main()
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
	fd = open("otis.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	printf("Two lines with newline:\n");
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
}
