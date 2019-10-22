/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 19:00:49 by eschoen           #+#    #+#             */
/*   Updated: 2019/10/22 13:14:01 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The memcmp() function compares byte string s1 against byte string s2.
** Both strings are assumed to be n bytes long. he memcmp() function returns
** zero if the two strings are identical, otherwise returns the difference
** between the first two differing bytes.
*/

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
