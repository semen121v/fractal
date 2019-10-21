/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optional_fractals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshade <fshade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:39:50 by eschoen           #+#    #+#             */
/*   Updated: 2019/10/16 11:37:32 by fshade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/fractol.h>

/*
** Фрактал который выглядит как курица))
*/

int			chiken(t_fractol *fractol)
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
		zr = FT_SQUARE(zr) - FT_SQUARE(zi) - cr - 0.69;
		zi = 1.2 * tmp_zr * fabs(zi) * -2.0 - ci;
		fractol->fractal.depth++;
	}
	return (fractol->fractal.depth);
}

/*
** Фрактал похожий на стоящего человека, повернутого на 90 градусов.
*/

int			man(t_fractol *fractol)
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
	while (FT_SQUARE(zr) + FT_SQUARE(zi) < 5 \
			&& fractol->fractal.depth < fractol->fractal.iteration)
	{
		tmp_zr = zr;
		zr = FT_SQUARE(zr) * FT_SQUARE(zr) + FT_SQUARE(zi) * FT_SQUARE(zi) - 6 \
				* FT_SQUARE(zr) * FT_SQUARE(zi) - cr - 0.35;
		zi = -5 * fabs(tmp_zr) * zi * (FT_SQUARE(tmp_zr) - FT_SQUARE(zi)) - ci;
		fractol->fractal.depth++;
	}
	return (fractol->fractal.depth);
}

/*
** Фрактал похожий на перекрестие.
*/

int			cross(t_fractol *fractol)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	fractol->fractal.depth = 0;
	zr = (fractol->mouse.pos_x - WIN_WIDTH) / ((double)WIN_WIDTH * 2) + 0.3;
	zi = (fractol->mouse.pos_y - WIN_HEIGHT) / ((double)WIN_HEIGHT) + 0.50;
	ci = fractol->fractal.width / fractol->fractal.scale + fractol->fractal.y;
	cr = fractol->fractal.height / fractol->fractal.scale + fractol->fractal.x;
	while (FT_SQUARE(zr) + FT_SQUARE(zi) < 4 \
			&& fractol->fractal.depth < fractol->fractal.iteration)
	{
		tmp_zr = zr;
		zr = -1 * (FT_SQUARE(zr) - (FT_SQUARE(zi) * 3.0)) * zr + cr + 0.42;
		zi = ((FT_SQUARE(tmp_zr) * 3.0) - FT_SQUARE(zi)) * zi + ci;
		fractol->fractal.depth++;
	}
	return (fractol->fractal.depth);
}

/*
** https://m-rush.ru/theory/item/246-julia-set-mnozhestvo-zhyulia.html
** Фрактальный круг, основаный на фрактале набора Julia.
** Получается через изменение некоторых параметров Julia).
*/

int			circle(t_fractol *fractol)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	fractol->fractal.depth = 0;
	cr = 0.139375;
	ci = -0.89250;
	zi = fractol->fractal.width / fractol->fractal.scale + fractol->fractal.y;
	zr = fractol->fractal.height / fractol->fractal.scale + fractol->fractal.x;
	while (FT_SQUARE(zr) + FT_SQUARE(zi) < 1 \
			&& fractol->fractal.depth < fractol->fractal.iteration)
	{
		tmp_zr = zr;
		zr = FT_SQUARE(zr) - FT_SQUARE(zi) + cr;
		zi = fabs(zi) * fabs(tmp_zr) + ci;
		fractol->fractal.depth++;
	}
	return (fractol->fractal.depth);
}
