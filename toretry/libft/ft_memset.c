/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 20:54:35 by ccariou           #+#    #+#             */
/*   Updated: 2021/12/05 20:38:29 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Function copies unsigned char c to the first n char of the string
 * pointd to by argument str.
*/

void	*ft_memset(void *b, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		((unsigned char *) b)[index] = (unsigned char) c;
		index ++;
	}
	return (b);
}
