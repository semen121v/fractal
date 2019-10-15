/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semenkravtsov <semenkravtsov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:26:15 by eschoen           #+#    #+#             */
/*   Updated: 2019/10/15 01:52:45 by semenkravts      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/fractol.h>

/*
** Вывод сообщения как использовать Fractol, если введено не 2 аргумента.
*/

static void		how_to_use_fractol(char *av0)
{
	ft_printf("Fractol usage: ");
	ft_printf("%s",av0);
	ft_printf(" [Fractol_name]\n");
	ft_printf(" [ julia | mandelbrot | psych_spots | circle | cross ");
	ft_printf("| man | chiken ]\n");
}

/*
** Позволяет управлять с помощью мыши и клавиатуры.
** Отлавливает события в указанном окне, при пойманном событии обращается
** к указанной функции.
*/

void			enable_control(t_fractol *fractol)
{
	mlx_hook(fractol->mlx.win, 2, 3, key_press, fractol);
	mlx_hook(fractol->mlx.win, 4, 3, mouse_press, fractol);
	mlx_hook(fractol->mlx.win, 6, 3, mouse_manipulate, fractol);
	mlx_loop(fractol->mlx.init);
}

/*
** Задаем фракталу начальные значения, которые подходили бы
** всем возможным вариантам фаркталов.
*/

void			fractol_initialization(t_fractol *fractol)
{
	fractol->fractal.x = -2.50;
	fractol->fractal.y = -1.25;
	fractol->fractal.scale = 320.00;
	fractol->fractal.iteration = 50;
	fractol->color.red = 0x95;
	fractol->color.green = 0x25;
	fractol->color.blue = 0x800;
	fractol->mouse.pos_x = WIN_WIDTH / 2;
	fractol->mouse.pos_y = WIN_HEIGHT / 2;
	if (fractol->fractal.type == 1 || fractol->fractal.type == 3 \
			|| fractol->fractal.type == 4)
	{
		fractol->fractal.x = -2.20;
		fractol->mouse.is_pressed = 1;
		if (fractol->fractal.type == 2 || fractol->fractal.type == 4)
			fractol->fractal.iteration = 120;
		if (fractol->fractal.type == 3)
			fractol->fractal.iteration = 15;
	}
}

/*
** Проверяем список доступных фракталов. Если фрактал недействителен,
** выходим из программы.
*/

static int		fractol_selecting(char *fractol_name, t_fractol *fractol)
{
	fractol->fractal.type = 0;
	if (ft_strequ(ft_str_to_lowcase(fractol_name), "julia"))
		fractol->fractal.type = 1;
	else if (ft_strequ(ft_str_to_lowcase(fractol_name), "mandelbrot"))
		fractol->fractal.type = 2;
	else if (ft_strequ(ft_str_to_lowcase(fractol_name), "psych_spots"))
		fractol->fractal.type = 3;
	else if (ft_strequ(ft_str_to_lowcase(fractol_name), "circle"))
		fractol->fractal.type = 4;
	else if (ft_strequ(ft_str_to_lowcase(fractol_name), "cross"))
		fractol->fractal.type = 5;
	else if (ft_strequ(ft_str_to_lowcase(fractol_name), "man"))
		fractol->fractal.type = 6;
	else if (ft_strequ(ft_str_to_lowcase(fractol_name), "chiken"))
		fractol->fractal.type = 7;
	else
	{
		ft_printf("%s is not a valid sesfsedparameter! Valid parameters are:\n", fractol_name);
		ft_printf("[ julia | mandelbrot | psych_spots | circle | ");
		ft_printf(" cross | man | chiken ]\n");
	}
	return (fractol->fractal.type);
}

/*
** https://fr.wikipedia.org/wiki/Liste_de_fractales_par_dimension_de_Hausdorff
** https://forum.intra.42.fr/topics/16334/messages
** Основная функция, малочит фрактальную структуру, создает и соединение между
** всеми элементами программы, что дает возможность рисовать на экране, получать
** вводы с клавиатуры и мыши (внутри функции fractol_match_the_norme для Нормы).
** str нужен чтобы потом зафришить строку заголовка окна (иначе утечка).
*/

int				main(int ac, char **av)
{
	t_fractol	*fractol;
	char		*str;

	if (ac == 2)
	{
		if ((fractol = (t_fractol *)malloc(sizeof(t_fractol))) == NULL)
		{
			ft_putstr("Error during Fractol Memory Allocation!\n");
			return (0);
		}
		if (fractol_selecting(av[1], fractol) == 0)
			return (0);
		fractol->mlx.init = mlx_init();
		str = ft_strjoin("fshade - Fractol - ", av[1]);
		fractol->mlx.win = mlx_new_window(fractol->mlx.init, WIN_WIDTH, \
			WIN_HEIGHT, str);
		fractol->mlx.img = mlx_new_image(fractol->mlx.init, WIN_WIDTH, \
			WIN_HEIGHT);
		fractol->image.data = mlx_get_data_addr(fractol->mlx.img, \
			&fractol->image.bpp, &fractol->image.size, &fractol->image.endian);
		fractol_match_the_norme(fractol, str);
	}
	else
		how_to_use_fractol(av[0]);
	return (0);
}
