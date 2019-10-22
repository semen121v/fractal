/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 20:20:31 by eschoen           #+#    #+#             */
/*   Updated: 2019/10/22 13:15:42 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description = Applies the function f to each character of the string passed
** as argument. Each character is passed by address to f to be modified if
** necessary.
** Param. #1 = The string to iterate.
** Param. #2 = The function to apply to each character of s.
** Return value = None.
*/

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int i;

	i = 0;
	if (s != NULL && f != NULL)
	{
		while (s[i] != '\0')
		{
			(*f)(&s[i]);
			i++;
		}
	}
}
