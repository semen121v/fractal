/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 10:15:50 by eschoen           #+#    #+#             */
/*   Updated: 2019/10/22 13:14:29 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description = Outputs the string s to the file descriptor fd followed by
** a ’\n’.
** Param. #1 = The string to output.
** Param. #2 = The file descriptor.
** Return value = None.
*/

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if (s != NULL && fd >= 0)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}
