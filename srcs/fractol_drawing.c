/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_drawing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschoen <eschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:29:03 by eschoen           #+#    #+#             */
/*   Updated: 2019/04/04 21:01:49 by eschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/fractol.h>

/*
** Помещает пиксель в определенную позицию, определенную функцией
** fractal_draw(). Меняет цвета в зависимости от уровня итерации. Если
** уровень итерации равен глубине фрактала, покраска идёт в черный цвет.
*/

static void		put_pixel(t_fractol *fractol, int depth)
{
	int			pos;

	pos = (fractol->fractal.height + (fractol->fractal.width * WIN_WIDTH)) * 4;
	if (fractol->fractal.height < WIN_WIDTH \
			&& fractol->fractal.width < WIN_HEIGHT \
				&& depth == fractol->fractal.iteration)
	{
		fractol->image.data[pos] = 0x00;
		fractol->image.data[pos + 1] = 0x00;
		fractol->image.data[pos + 2] = 0x00;
	}
	else if (fractol->fractal.height < WIN_WIDTH \
				&& fractol->fractal.width < WIN_HEIGHT)
	{
		fractol->image.data[pos] = fractol->color.red + (depth * 2.42);
		fractol->image.data[pos + 1] = fractol->color.green + (depth * 2.42);
		fractol->image.data[pos + 2] = fractol->color.blue + (depth * 2.42);
	}
}

/*
** Рисует фрактал из fractal.type (выборка) и размещает его на
** изображение окна. Цвета будут зависеть от "уровня глубины", каждая
** фрактальная функция будет возвращать этот уровень.
*/

static void		*fractal_draw(void *tab)
{
	t_fractol	*fractol;
	int			depth;
	double		temp_width;

	fractol = (t_fractol *)tab;
	temp_width = fractol->fractal.width;
	while (fractol->fractal.height < WIN_WIDTH)
	{
		fractol->fractal.width = temp_width;
		while (fractol->fractal.width < fractol->fractal.limit)
		{
			depth = (fractol->fractal.type == 1) ? julia(fractol) : depth;
			depth = (fractol->fractal.type == 2) ? mandelbrot(fractol) : depth;
			depth = (fractol->fractal.type == 3) ? psych_spots(fractol) : depth;
			depth = (fractol->fractal.type == 4) ? circle(fractol) : depth;
			depth = (fractol->fractal.type == 5) ? cross(fractol) : depth;
			depth = (fractol->fractal.type == 6) ? man(fractol) : depth;
			depth = (fractol->fractal.type == 7) ? chiken(fractol) : depth;
			put_pixel(fractol, depth);
			fractol->fractal.width++;
		}
		fractol->fractal.height++;
	}
	return (tab);
}

/*
** http://man7.org/linux/man-pages/man3/pthread_create.3.html
** Изображение передается этой функции, разделяя его на меньшие участки для
** многопоточности (part). После того, как все изображения были сгенерированы,
** полученное изображение помещается в окно.
*/

static void		fractol_flow(t_fractol *fractol)
{
	int			i;
	t_fractol	part[FLOWS];
	pthread_t	t[FLOWS];

	i = 0;
	while (i < FLOWS)
	{
		ft_memcpy((void *)&part[i], (void *)fractol, sizeof(t_fractol));
		part[i].fractal.width = ((double)(1.00 / FLOWS) * WIN_WIDTH) * i;
		part[i].fractal.limit = ((double)(1.00 / FLOWS) * WIN_WIDTH) * (i + 1);
		i++;
	}
	i = 0;
	while (i < FLOWS)
	{
		pthread_create(&t[i], NULL, fractal_draw, &part[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(fractol->mlx.init, fractol->mlx.win, \
								fractol->mlx.img, 0, 0);
}

/*
** Рисует первый раз и далее обновляет изображение фрактала.
** Путём обновления его значений, а также печатает количество
** итераций и масштабирование фрактала.
*/

void			fractol_drawing(t_fractol *fractol)
{
	char		*str1;
	char		*str2;
	char		*str3;
	char		*str4;

	if (fractol->fractal.iteration <= 0)
		fractol->fractal.iteration = 0;
	fractol_flow(fractol);
	str1 = ft_itoa(fractol->fractal.iteration);
	str2 = ft_itoa((int)fractol->fractal.scale);
	str3 = ft_strjoin("Iterations quantity : ", str1);
	str4 = ft_strjoin("Zoom scale: ", str2);
	mlx_string_put(fractol->mlx.init, fractol->mlx.win, 15, 10, 0xFFFF00, str3);
	mlx_string_put(fractol->mlx.init, fractol->mlx.win, 15, 40, 0xFFFF00, str4);
	free(str1);
	free(str2);
	free(str3);
	free(str4);
}
