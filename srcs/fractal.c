/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:45:04 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/15 16:45:05 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_mandelbrot(t_env *e)
{
	e->x1 = -2.1;
	e->x2 = 0.6;
	e->y1 = -1.2;
	e->y2 = 1.2;
}

static void	init_julia(t_env *e)
{
	e->x1 = -1;
	e->x2 = 1;
	e->y1 = -1.2;
	e->y2 = 1.2;
}

static void	init_burningship(t_env *e)
{
	e->x1 = -2;
	e->x2 = 1.5;
	e->y1 = -2;
	e->y2 = 1.5;
}

void		fractal_init(t_env *e)
{
	e->p_coefx = 0;
	e->p_coefy = 0;
	e->iteration = 0;
	e->color = 1;
	e->p_x = 0;
	e->p_y = 0;
	e->pause = 0;
	e->menu = 0;
	if (e->id == 1)
		init_mandelbrot(e);
	else if (e->id == 2)
		init_julia(e);
	else if (e->id == 3)
		init_burningship(e);
}

void		fractal(int id)
{
	t_env	e;
	char	*name[3];

	name[0] = "Mandelbrot";
	name[1] = "Julia";
	name[2] = "BurningShip";
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_W, WIN_H, name[id - 1]);
	e.id = id;
	fractal_init(&e);
	mlx_image(&e);
	mlx_hook(e.win, MotionNotify, PointerMotionMask, pointerhook, &e);
	mlx_hook(e.win, KeyPress, Button2MotionMask, keyhook, &e);
	mlx_mouse_hook(e.win, mousehook, &e);
	expose(&e);
	mlx_loop(e.mlx);
}
