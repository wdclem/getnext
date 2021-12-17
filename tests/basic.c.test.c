/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:16:43 by ccariou           #+#    #+#             */
/*   Updated: 2021/12/16 14:05:34 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int		fd;
	int		retget;
	char	*tmp;
	char	**line;
	int		n = 1;

	line = &tmp;
	fd = open("8charsnlx8", O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		retget = get_next_line(fd, line);
		if (retget < 0)
			break;
		printf("%s<- end of line %d\n", *line, n);
		free(*line);
		n++;
	}
	close (fd);
	return(0);
}
