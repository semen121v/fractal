/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charinwordcalc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:23:09 by eschoen           #+#    #+#             */
/*   Updated: 2019/10/22 13:12:53 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_charinwordcalc(char *str, char sep)
{
	int i;
	int qty;

	i = 0;
	qty = 0;
	while (str[i] != '\0' && str[i] == sep)
		i++;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] != sep)
			i++;
		qty++;
		while (str[i] != '\0' && str[i] == sep)
			i++;
	}
	return (qty);
}
