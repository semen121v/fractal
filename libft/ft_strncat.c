/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 13:52:16 by eschoen           #+#    #+#             */
/*   Updated: 2019/10/22 13:16:15 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION = The strncat() functions append a copy of the null-terminated
** string s2 to the end of the null-terminated string s1, then add a
** terminating `\0'. The string s1 must have sufficient space to hold the
** result. The strncat()function appends not more than n characters from s2,
** and then adds a terminating `\0'.
** RETURN VALUES = The strcat() and strncat() functions return the pointer s1.
*/

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0' && j < n)
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
