/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:29:38 by ccariou           #+#    #+#             */
/*   Updated: 2021/12/06 11:05:56 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Function search for the last occurence of c in str
 */

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	index = ft_strlen(s);
	while (index >= 0)
	{
		if (s[index] == c)
			return ((char *) s + index);
		index --;
	}
	return (0);
}
