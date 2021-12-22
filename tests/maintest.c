/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:05:01 by ccariou           #+#    #+#             */
/*   Updated: 2021/12/07 19:45:11 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUF_SIZE 10

int	main(void)
{
	int	fd;
	int ret;
	char buf[BUF_SIZE + 1];

	fd = open("tau", O_RDONLY);
	/* fd = open("tau", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR); */
	if (fd == -1)
	{
		ft_putstr("open() error");
		return (1);
	}
	while (ret = read(fd, buf, BUF_SIZE))
	{
		buf[ret] = '\0';
		ft_putnbr(ret);
		ft_putstr(buf);
	}
	ft_putnbr(ret);
	if (close(fd) == -1)
	{
		ft_putstr("close() error");
		return (1);
	}
	return (0);
}
