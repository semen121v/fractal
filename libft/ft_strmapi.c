/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 20:29:31 by eschoen           #+#    #+#             */
/*   Updated: 2019/10/22 13:16:12 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description = Applies the function f to each character of the string passed
** as argument by giving its index as first argument to create a “fresh” new
** string (with malloc(3)) resulting from the successive applications of f.
** Param. #1 = The string to map.
** Param. #2 = The function to apply to each character of s and its index.
** Return value = The “fresh” string created from the successive applications
** of f.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		newstr = ft_strnew(ft_strlen(s));
		if (newstr == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			newstr[i] = (*f)(i, s[i]);
			i++;
		}
		return (newstr);
	}
	return (NULL);
}
