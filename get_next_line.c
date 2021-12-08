/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:11:20 by ccariou           #+#    #+#             */
/*   Updated: 2021/12/08 16:53:49 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

#define BUF_SIZE 1


int	get_next_line(const int fd, char **line)
{
	size_t	len;
	size_t	ret;
	int	fill;
	char buf[BUF_SIZE + 1];
/* handle fd potential errors simplify to < 3 */
	if (fd < 0 || fd == 0 || fd == 1 || fd == 2 || !line)
		return (-1)
	fill = read(fd, buf, BUF_SIZE);
	//if fill == o or == -1
	printf("fill %i\n", fill);
	/* if fill exist duplicate the content */
	len = ft_strlen((char *) buf);
	while () 
	{
		strcpy((char *) buf, *line);
		for(int i = 0; i < len; i++)
		{
			line[i] = (char *)buf[i];
	 	}
	}
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
	return (0);
}

int	main()
{
	int		fd;
	int		retget;
	char	*line = NULL;

	fd = open("h.txt", O_RDONLY);
	retget = get_next_line(fd, &line);
	printf("%i\n%s\n", retget, line);
	return(0);
}
