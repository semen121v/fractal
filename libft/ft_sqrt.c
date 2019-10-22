/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:10:36 by eschoen           #+#    #+#             */
/*   Updated: 2019/10/22 13:14:52 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Calculate non-negative square root of x. If x is negative, the function
** wil return zero (0).
*/

double		ft_sqrt(double x)
{
	long	i;

	i = 1;
	if (x < 0)
		return (0);
	while (i * i < x)
		i++;
	return (i);
}
