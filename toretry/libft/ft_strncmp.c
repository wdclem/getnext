/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:27:41 by ccariou           #+#    #+#             */
/*   Updated: 2021/12/05 20:10:40 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Fucntion compare two strings for size n length
 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (((unsigned char *) s1)[i] - ((unsigned char *)s2)[i]);
		i ++;
	}
	return (0);
}
