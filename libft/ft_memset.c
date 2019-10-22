/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 13:56:33 by eschoen           #+#    #+#             */
/*   Updated: 2019/10/22 13:14:16 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION = The memset() function writes len bytes of value c (converted
** to an unsigned char) to the string b.
** RETURN VALUES = The memset() function returns its first argument.
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
