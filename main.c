/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:16:43 by ccariou           #+#    #+#             */
/*   Updated: 2021/12/17 14:20:45 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int		fd;
	char	*line;
	int		n = 1;

	sleep (1);
	line = NULL;
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
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s<- end of line %d\n", line, n);
		free(line);
		n++;
	}
	close (fd);
	return(0);
}
