/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 20:10:59 by eschoen           #+#    #+#             */
/*   Updated: 2019/10/22 13:15:32 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description = Takes as a parameter the address of a string that need to be
** freed with free(3), then sets its pointer to NULL.
** Param. #1 = The string’s address that needs to be freed and its pointer set
** to NULL.
** Return value = None.
*/

#include "libft.h"

void	ft_strdel(char **as)
{
	if (as != NULL)
		ft_memdel((void **)as);
}
