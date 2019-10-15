/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:53:52 by eschoen           #+#    #+#             */
/*   Updated: 2018/12/29 19:36:21 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION = The atoi() function converts the initial portion of the string
** pointed to by str to int representation.
*/

#include "libft.h"

int		ft_atoi(const char *str)
{
	int nbr;
	int neg;
	int i;

	nbr = 0;
	i = 0;
	while (ft_isspace(*str))
		str++;
	neg = (*str == '-');
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
		i++;
	}
	if (i >= 19)
	{
		if ((nbr * 10) / 10 != 10 && neg == 1)
			return (0);
		if ((nbr * 10) / 10 != 10 && neg == 0)
			return (-1);
	}
	return (neg ? -nbr : nbr);
}
