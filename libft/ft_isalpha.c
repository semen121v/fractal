/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:39:43 by eschoen           #+#    #+#             */
/*   Updated: 2019/10/22 13:13:08 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalpha(int ch)
{
	if (ch >= 65 && ch <= 90)
		return (1);
	if (ch >= 97 && ch <= 122)
		return (1);
	return (0);
}
