/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:38:19 by ccariou           #+#    #+#             */
/*   Updated: 2021/12/06 12:03:36 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Function to free array/2d array
 */

void	ft_freearray(char **array, int i)
{
    while (i--)
        free(words[i]);
    ft_strdel(words);
    return (NULL);
}
