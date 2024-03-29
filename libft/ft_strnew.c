/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 20:07:30 by eschoen           #+#    #+#             */
/*   Updated: 2019/10/22 13:16:28 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description = Allocates (with malloc(3)) and returns a “fresh” string
** ending with ’\0’. Each character of the string is initialized at ’\0’.
** If the allocation fails the function returns NULL.
** Param. #1 = The size of the string to be allocated.
** Return value = The string allocated and initialized to 0.
*/

#include "libft.h"

char	*ft_strnew(size_t size)
{
	return (ft_memalloc((size + 1) * sizeof(char)));
}
