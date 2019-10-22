/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:52:07 by eschoen           #+#    #+#             */
/*   Updated: 2019/10/22 13:13:57 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The memchr() function locates the first occurrence of c (converted to an
** unsigned char) in string s. The memchr() function returns a pointer to the
** byte located, or NULL if no such byte exists within n bytes.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (((void *)&((unsigned char *)s)[i]));
		i++;
	}
	return (NULL);
}
