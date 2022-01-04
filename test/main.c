/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:16:43 by ccariou           #+#    #+#             */
/*   Updated: 2022/01/04 13:48:27 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i = 0;
	int		j = 0;

	line = NULL;
	fd = 0;

	if (argc == 1)
	{
		while (get_next_line(0, &line) > 0)
		{
			printf("%s<- end of line\n", line);
			free(line);
		}
	}
	else if (argc == 6)
	{
		int mfd[5] = {0, 0, 0, 0, 0};

		mfd[0] = open(argv[1], O_RDONLY);
		mfd[1] = open(argv[2], O_RDONLY);
		mfd[2] = open(argv[3], O_RDONLY);
		mfd[3] = open(argv[4], O_RDONLY);
		mfd[4] = open(argv[5], O_RDONLY);

		while(j < 6)
		{
			i = 0;
			while(i < 5)
			{
				if(get_next_line(mfd[i], &line) > 0)
				printf("%s<- end of line\n", line);
				i++;
			}
			j++;
		}
		j = 0;
		while(j < 6)
			close(mfd[j++]);
	}
	else
	{
			fd = open(argv[1], O_RDONLY);
			while((get_next_line(fd, &line) > 0))
				{
					ft_putchar('\n');
					printf("%s<- end of line \n", line);
					free(line);
				}
			close(fd);
		}
	close (fd);
	return(0);
}
