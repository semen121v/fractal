/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 20:17:23 by eschoen           #+#    #+#             */
/*   Updated: 2019/10/22 13:15:22 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description = Sets every character of the string to the value ’\0’.
** Param. #1 = The string that needs to be cleared.
** Return value = None.
*/

#include "libft.h"

void	ft_strclr(char *s)
{
	int i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			s[i] = '\0';
			i++;
		}
	}
}
