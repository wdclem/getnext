/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:02:23 by ccariou           #+#    #+#             */
/*   Updated: 2021/12/05 20:24:33 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Function count the length of the string str, excluding null char>
*/

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
	{
		index ++;
	}
	return (index);
}
