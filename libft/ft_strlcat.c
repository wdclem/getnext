/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:20:41 by ccariou           #+#    #+#             */
/*   Updated: 2021/12/05 20:34:04 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Function put a null terminated string source at the end of dest.
 ** done at the strlen(dest) - 1 bytes, \0 terminating.
 ** return length dest + src.
 */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	j = dlen;
	i = 0;
	if (dstsize < dlen)
		return (slen + dstsize);
	while ((dstsize > j + 1) && src[i])
	{
		dst[j] = src[i];
		i ++;
		j ++;
	}
	dst[j] = '\0';
	return (dlen + slen);
}
