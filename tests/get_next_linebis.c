/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:54:13 by ccariou           #+#    #+#             */
/*   Updated: 2021/12/21 11:41:26 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int    ft_copyline(char **result, char **line, const int fd)
{
    int        index;
    char    *tmp;

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
    else
    {
        *line = ft_strdup(result[fd]);
        ft_strdel(&result[fd]);
    }
    return (1);
}

int    get_next_line(const int fd, char **line)
{
    size_t        ret;
    static char    *result[FD_SIZE];
    char            *tmp;
    char            buf[BUFF_SIZE + 1];

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
        ret = read(fd, buf, BUFF_SIZE);
        buf[ret] = '\0';
    }
    if (ret == 0 && !result[fd])
        return (0);
    return (ret);
}
