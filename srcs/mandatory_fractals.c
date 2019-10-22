/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_fractals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:35:54 by eschoen           #+#    #+#             */
/*   Updated: 2019/10/22 13:09:17 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/fractol.h>

/*
** Fractol № 3:
**
** https://aftershock.news/?q=node/488635&full
** Фрактал, имитирующий тест Роршаха. Это психологический тест, в котором
** записывается восприятие чернильных пятен субъектами, а затем анализируется
** с использованием психологической интерпретации, сложных алгоритмов или
** обоих. Поразительной характеристикой чернильных пятен Роршаха является их
** симметрия, поэтому этот тип фрактала очень забавен.
*/

int			psych_spots(t_fractol *fractol)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	fractol->fractal.depth = 0;
	cr = (fractol->mouse.pos_x - WIN_WIDTH) / ((double)WIN_WIDTH * 2) + 0.25;
	ci = (fractol->mouse.pos_y - WIN_HEIGHT) / ((double)WIN_HEIGHT) + 0.50;
	zi = fractol->fractal.width / fractol->fractal.scale + fractol->fractal.y;
	zr = fractol->fractal.height / fractol->fractal.scale + fractol->fractal.x;
	while (FT_SQUARE(zr) + FT_SQUARE(zi) < 4 \
			&& fractol->fractal.depth < fractol->fractal.iteration)
	{
		tmp_zr = fabs(zr);
		zr = FT_SQUARE(zr) - FT_SQUARE(zi) - cr;
		zi = (2 * zi) * tmp_zr - ci;
		fractol->fractal.depth++;
	}
	return (fractol->fractal.depth);
}

/*
** Fractol № 2:
**
** http://www.opita.net/node/172
** http://grafika.me/node/49
** Выборка комплексных чисел и определение для каждой точки выборки (ci и cr),
** идет ли результат итерации вышеуказанной функции в бесконечность.
** Рассматривая реальную и мнимую части C как координаты изображения (x + y)
** на комплексной плоскости, пиксели могут быть окрашены в зависимости от того,
** насколько быстро последовательность расходится (глубина), а цвет 0 (черный)
** используется для точек, где последовательность не расходится
** (итерация == глубина).
*/

int			mandelbrot(t_fractol *fractol)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	fractol->fractal.depth = 0;
	zr = (fractol->mouse.pos_x - WIN_WIDTH) / ((double)WIN_WIDTH * 2) + 0.25;
	zi = (fractol->mouse.pos_y - WIN_HEIGHT) / ((double)WIN_HEIGHT) + 0.50;
	ci = fractol->fractal.width / fractol->fractal.scale + fractol->fractal.y;
	cr = fractol->fractal.height / fractol->fractal.scale + fractol->fractal.x;
	while (FT_SQUARE(zr) + FT_SQUARE(zi) < 4 \
			&& fractol->fractal.depth < fractol->fractal.iteration)
	{
		tmp_zr = zr;
		zr = FT_SQUARE(zr) - FT_SQUARE(zi) + cr;
		zi = (2 * zi) * tmp_zr + ci;
		fractol->fractal.depth++;
	}
	return (fractol->fractal.depth);
}

/*
** Fractol № 1:
**
** https://lodev.org/cgtutor/juliamandelbrot.html
** http://www.relativitybook.com/CoolStuff/julia_set.html
**
** Набор, состоящий из значений, генерируемых математической функцией, такой,
** что сколь угодно малое возмущение может вызвать резкие изменения в
** последовательности значений итерационных функций.
*/

int			julia(t_fractol *fractol)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	fractol->fractal.depth = 0;
	cr = (fractol->mouse.pos_x - (200.0 / 2.0) - WIN_WIDTH) \
			/ ((double)WIN_WIDTH * 2) + 0.15;
	ci = (fractol->mouse.pos_y - (300.0 / 2.0) - WIN_HEIGHT) \
			/ (double)WIN_HEIGHT - 0.15;
	zi = fractol->fractal.width / fractol->fractal.scale + fractol->fractal.y;
	zr = fractol->fractal.height / fractol->fractal.scale + fractol->fractal.x;
	while (FT_SQUARE(zr) + FT_SQUARE(zi) < 4 \
			&& fractol->fractal.depth < fractol->fractal.iteration)
	{
		tmp_zr = zr;
		zr = FT_SQUARE(zr) - FT_SQUARE(zi) + cr;
		zi = (2 * zi) * tmp_zr + ci;
		fractol->fractal.depth++;
	}
	return (fractol->fractal.depth);
}
