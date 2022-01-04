/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:28:06 by ccariou           #+#    #+#             */
/*   Updated: 2021/11/23 20:16:01 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* applies function f to each char of the string
 */

void	ft_striter(char *s, void (*f)(char *))
{
	if (s != NULL)
	{
		while (*s && *f)
		{
			(*f)(s);
			s ++;
		}
	}
}
