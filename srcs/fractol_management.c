/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semen <semen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:28:49 by eschoen           #+#    #+#             */
/*   Updated: 2019/10/16 22:18:36 by semen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/fractol.h>

/*
** Для закрытия приложения Fractol.
*/

int				ft_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

/*
** Если состояние мыши = включено (1), получаем координаты X и y курсора мыши
** и продолжаем обновлять его до фрактальной структуры. Это нужно для
** манипулирования параметрами фракталов (ci и cr).
*/

int				mouse_manipulate(int x, int y, t_fractol *fractol)
{
	if (fractol->mouse.is_pressed == 1 && (x > 0 && y > 0) \
			&& (x < WIN_WIDTH && y < WIN_HEIGHT))
	{
		fractol->mouse.pos_x = x;
		fractol->mouse.pos_y = y;
		fractol_drawing(fractol);
	}
	return (0);
}

/*
** Назначаем код мыши к конкретным операциям, например, изменение цвета,
** уровня масштабирования и изменение параметров фрактала.
** фрактала.
**
** См. коды клавиш мыши:
** ** https://forum.intra.42.fr/topics/19254/messages?page=1
*/

int				mouse_press(int mousecode, int x, int y, t_fractol *fractol)
{
	if (x > 0 && y > 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		if (mousecode == 5)
			zoom_plus(x, y, fractol);
		else if (mousecode == 4)
			zoom_minus(fractol);
		else if (mousecode == 3)
			fractol_initialization(fractol);
		else if (mousecode == 2)
			diffrent_colors(fractol);
		else if (mousecode == 1)
			fractol->mouse.is_pressed = (fractol->mouse.is_pressed == 1) \
			? 0 : 1;
		fractol_drawing(fractol);
	}
	return (0);
}

/*
** Назначаем коды клавиш к конкретным операциям, например, изменение цвета,
** перемещение фрактала, уровень масштабирования, количество итераций и т. д.
**
** См. коды клавиш клавиатуры:
** ** https://forum.intra.42.fr/topics/19254/messages?page=1
*/

int				key_press(int keycode, t_fractol *fractol)
{
	if (keycode == 53)
		ft_close(0);
	else if (keycode == 13 || keycode == 126)
		fractol->fractal.y -= 10 / fractol->fractal.scale;
	else if (keycode == 0 || keycode == 123)
		fractol->fractal.x -= 10 / fractol->fractal.scale;
	else if (keycode == 1 || keycode == 125)
		fractol->fractal.y += 10 / fractol->fractal.scale;
	else if (keycode == 2 || keycode == 124)
		fractol->fractal.x += 10 / fractol->fractal.scale;
	else if (keycode == 24 || keycode == 69 || keycode == 27 || keycode == 78 \
				|| keycode == 12)
		fractal_iteration(fractol, keycode);
	else if (keycode == 15)
		fractol_initialization(fractol);
	else if (keycode == 8)
		diffrent_colors(fractol);
	else if (keycode == 47)
		fractol->fractal.iteration++;
	else if (keycode == 43)
		fractol->fractal.iteration--;
	fractol_drawing(fractol);
	return (0);
}
