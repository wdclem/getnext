/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:22:36 by ccariou           #+#    #+#             */
/*   Updated: 2021/12/05 19:59:16 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Function find the first occurence of a character in a buffer
 */

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*src;

	index = 0;
	src = (unsigned char *) s;
	while (index < n)
	{
		if (src[index] == (unsigned char) c)
			return (src + index);
		index ++;
	}
	return (NULL);
}
