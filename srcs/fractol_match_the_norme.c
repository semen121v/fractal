/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_match_the_norme.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semenkravtsov <semenkravtsov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 13:45:43 by eschoen           #+#    #+#             */
/*   Updated: 2019/10/15 01:43:29 by semenkravts      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/fractol.h>

/*
** Вначале чистим указатель на строку str (имя окна), так как она более не
** нужна (текст уже выведен в заголовок окна).
** Далее инициализируем фрактал (задаем некие начальные значения).
** Затем производим первую отрисовку.
** И передаем управление пользователю с клавиатуры и мышки.
*/

void			fractol_match_the_norme(t_fractol *fractol, char *str)
{
	free(str);
	fractol_initialization(fractol);
	fractol_drawing(fractol);
	enable_control(fractol);
}
