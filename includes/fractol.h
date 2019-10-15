/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semenkravtsov <semenkravtsov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:29:18 by eschoen           #+#    #+#             */
/*   Updated: 2019/10/15 01:53:41 by semenkravts      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <stdlib.h> for NULL
** <pthread.h> for parallel computing. See also:
** https://ru.wikipedia.org/wiki/POSIX_Threads
**
** <math.h> for sin() and cos()
** <time.h> for random generating
** "mlx.h" as graphical library
** "libft.h" as main library for this project.
**
** See also:
** https://forum.intra.42.fr/topics/20307/messages/1#107578
** https://forum.intra.42.fr/topics/19254/messages?page=1
*/

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <pthread.h>
# include <math.h>
# include <time.h>

# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"

# define ZOOM_LIMIT		(900000000)
# define SCALE_ACCURACY	(1.05)
# define WIN_WIDTH		(1200)
# define WIN_HEIGHT		(800)
# define FLOWS			(12)
# define FT_SQUARE(x)	(x * x)

typedef struct	s_mlx
{
	void	*init;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct	s_image
{
	char	*data;
	int		size;
	int		endian;
	int		bpp;
}				t_image;

typedef struct	s_color
{
	int		red;
	int		green;
	int		blue;
}				t_color;

typedef struct	s_type
{
	int		type;
	int		depth;
	int		iteration;
	double	width;
	double	height;
	double	scale;
	double	limit;
	double	x;
	double	y;
}				t_type;

typedef struct	s_mouse
{
	int		is_pressed;
	int		pos_x;
	int		pos_y;
}				t_mouse;

typedef struct	s_fractol
{
	t_mlx	mlx;
	t_image	image;
	t_color	color;
	t_type	fractal;
	t_mouse	mouse;
}				t_fractol;

void			fractol_initialization(t_fractol *fractol);
void			fractol_drawing(t_fractol *fractol);
int				key_press(int keycode, t_fractol *fractol);
int				mouse_press(int mousecode, int x, int y, t_fractol *fractol);
int				mouse_manipulate(int x, int y, t_fractol *fractol);
void			zoom_plus(int x, int y, t_fractol *fractol);
void			zoom_minus(t_fractol *fractol);
void			diffrent_colors(t_fractol *fractol);
void			fractol_match_the_norme(t_fractol *fractol, char *str);
void			enable_control(t_fractol *fractol);

int				julia(t_fractol *fractol);
int				mandelbrot(t_fractol *fractol);
int				psych_spots(t_fractol *fractol);

int				circle(t_fractol *fractol);
int				cross(t_fractol *fractol);
int				man(t_fractol *fractol);
int				chiken(t_fractol *fractol);

#endif
