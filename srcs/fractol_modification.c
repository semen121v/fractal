/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_modification.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 20:13:42 by eschoen           #+#    #+#             */
/*   Updated: 2019/10/22 12:42:59 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/fractol.h>

/*
** Раскрашиваем фрактал случайным цветом для красоты.
*/

void		diffrent_colors(t_fractol *fractol)
{
	fractol->color.red = (rand() % (0x5F + 0x01));
	fractol->color.green = (rand() % (0x5F + 0x01));
	fractol->color.blue = (rand() % (0x5F + 0x01));
}

/*
** Увеличивает масштаб фрактала в зависимости от положения мыши (x и y).
** Сохраняет позицию в x_pos и y_pos, используемые
** позже функцией zoom_minus(). Если фрактал является circle, то
** итерации не будут увеличиваться. Уровень масштабирования ограничен
** макросом ZOOM_LIMIT.
*/

void		zoom_plus(int x, int y, t_fractol *fractol)
{
	if (fractol->fractal.scale >= ZOOM_LIMIT)
	{
		fractol->fractal.scale = ZOOM_LIMIT;
		return ;
	}
	if (fractol->mouse.is_pressed == 1)
	{
		fractol->mouse.pos_x = x;
		fractol->mouse.pos_y = y;
	}
	fractol->fractal.x = (x / fractol->fractal.scale + fractol->fractal.x) - \
		((fractol->fractal.scale * SCALE_ACCURACY) / 2);
	fractol->fractal.x += ((fractol->fractal.scale * SCALE_ACCURACY) / 2) - \
		(x / (fractol->fractal.scale * SCALE_ACCURACY));
	fractol->fractal.y = (y / fractol->fractal.scale + fractol->fractal.y) - \
		((fractol->fractal.scale * SCALE_ACCURACY) / 2);
	fractol->fractal.y += ((fractol->fractal.scale * SCALE_ACCURACY) / 2) - \
		(y / (fractol->fractal.scale * SCALE_ACCURACY));
	fractol->fractal.scale *= SCALE_ACCURACY;
}

/*
** Уменьшите масштаб. Использует положение мыши из функции
** zoom_plus (). Если фрактал является сферой, то итерации не будут
** уменьшаться.
*/

void		zoom_minus(t_fractol *fractol)
{
	fractol->fractal.x = (fractol->mouse.pos_x / fractol->fractal.scale + \
		fractol->fractal.x) - ((fractol->fractal.scale / SCALE_ACCURACY) / 2);
	fractol->fractal.x += ((fractol->fractal.scale / SCALE_ACCURACY) / 2) - \
		(fractol->mouse.pos_x / (fractol->fractal.scale / SCALE_ACCURACY));
	fractol->fractal.y = (fractol->mouse.pos_y / fractol->fractal.scale + \
		fractol->fractal.y) - ((fractol->fractal.scale / SCALE_ACCURACY) / 2);
	fractol->fractal.y += ((fractol->fractal.scale / SCALE_ACCURACY) / 2) - \
		(fractol->mouse.pos_y / (fractol->fractal.scale / SCALE_ACCURACY));
	fractol->fractal.scale /= SCALE_ACCURACY;
}

void		fractal_iteration(t_fractol *fractol, int keycode)
{
	if (keycode == 24 || keycode == 69)
		fractol->fractal.iteration = fractol->fractal.iteration \
			+ fractol->fractal.i;
	else if (keycode == 36)
	{
		fractol->fractal.i = fractol->fractal.i + 10;
		return ;
	}
	else if (keycode == 51)
	{
		if (fractol->fractal.i > 1)
			fractol->fractal.i = fractol->fractal.i - 10;
		return ;
	}
	else
		fractol->fractal.iteration = fractol->fractal.iteration \
			- fractol->fractal.i;
}
