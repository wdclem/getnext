/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:41:20 by ccariou           #+#    #+#             */
/*   Updated: 2021/12/05 20:35:24 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Function put the string source after string dest.
*/

char	*ft_strcat(char *s1, const char *s2)
{
	int		idest;
	int		isrc;

	idest = 0;
	isrc = 0;
	while (s1[idest])
		idest ++;
	while (s2[isrc])
	{
		s1[idest] = s2[isrc];
		idest ++;
		isrc ++;
	}
	s1[idest] = '\0';
	return (s1);
}
