/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:59:36 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/09 19:59:37 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_image(t_env *e)
{
	int bpp;
	int sl;
	int endian;

	bpp = sizeof(int);
	sl = bpp * WIN_W;
	endian = 0;
	e->img = mlx_new_image(e->mlx, WIN_W, WIN_H);
	e->data = mlx_get_data_addr(e->img, &bpp, &sl, &endian);
}

int		expose(t_env *e)
{
	if (e->id == 1)
		mandelbrot(e);
	else if (e->id == 2)
		julia(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	if (e->pause == 1)
		mlx_string_put(e->mlx, e->win, 20, 10, 0xFF0000, "Pause");
	if (e->menu == 0)
		mlx_string_put(e->mlx, e->win, 10, 470, 0xFFFFFF, "Menu : m");
	if (e->menu == 1)
	{
		mlx_string_put(e->mlx, e->win, 10, 350, 0xFFFFFF, "Move : arrow");
		mlx_string_put(e->mlx, e->win, 10, 350, 0xFFFFFF, "Iteration : +/-");
		mlx_string_put(e->mlx, e->win, 10, 370, 0xFFFFFF, "Color : c");
		mlx_string_put(e->mlx, e->win, 10, 390, 0xFFFFFF, "Reset : r");
		mlx_string_put(e->mlx,
			e->win, 10, 410, 0xFFFFFF, "Zoom : p_up/p_down/roulette");
		mlx_string_put(e->mlx, e->win, 10, 430, 0xFFFFFF, "Pause : space");
		mlx_string_put(e->mlx, e->win, 10, 450, 0xFFFFFF, "Exit : Esc");
		mlx_string_put(e->mlx, e->win, 10, 470, 0xFFFFFF, "Exit menu : m");
	}
	return (0);
}

void	mlx_clear_set_image(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	mlx_clear_window(e->mlx, e->win);
	mlx_image(e);
}

void	fill_pixel(char **img, int x, int y, int color)
{
	if (x < WIN_W && y < WIN_H && x >= 0 && y >= 0)
	{
		((int*)*img)[x + (y * WIN_W)] = color;
	}
}
