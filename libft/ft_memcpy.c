/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:35:17 by eschoen           #+#    #+#             */
/*   Updated: 2019/10/22 13:14:05 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION = The memcpy() function copies n bytes from memory area src to
** memory area dst.  If dst and src overlap, behavior is undefined.
** Applications in which dst and src might overlap should use memmove instead.
** RETURN VALUES = The memcpy() function returns the original value of dst.
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
