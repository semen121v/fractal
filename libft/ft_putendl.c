/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 09:58:32 by eschoen           #+#    #+#             */
/*   Updated: 2019/10/22 13:14:32 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description = Outputs the string s to the standard output followed by a ’\n’.
** Param. #1 = The string to output.
** Return value = None.
*/

#include "libft.h"

void	ft_putendl(char const *s)
{
	if (s != NULL)
	{
		ft_putstr(s);
		ft_putchar('\n');
	}
}
