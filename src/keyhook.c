/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 19:31:56 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/07 19:31:58 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	move_arrow(int keycode, t_env *e)
{
	if (keycode == 125 && (e->y1 > LIMIT_MIN
		&& e->y2 > LIMIT_MIN))
	{
		e->y1 -= 0.1;
		e->y2 -= 0.1;
	}
	if (keycode == 126 && (e->y1 < LIMIT_MAX
		&& e->y2 < LIMIT_MAX))
	{
		e->y1 += 0.1;
		e->y2 += 0.1;
	}
	if (keycode == 124 && e->x1 > LIMIT_MIN
		&& e->x2 > LIMIT_MIN)
	{
		e->x1 -= 0.1;
		e->x2 -= 0.1;
	}
	if (keycode == 123 && e->x1 < LIMIT_MAX
		&& e->x2 < LIMIT_MAX)
	{
		e->x1 += 0.1;
		e->x2 += 0.1;
	}
}

static void	iteration(int keycode, t_env *e)
{
	if (keycode == 69 && e->iteration < LIMIT_MAX)
		e->iteration += 10;
	if (keycode == 78 && e->iteration > LIMIT_MIN)
		e->iteration -= 10;
}

static void	zoom(int keycode, t_env *e)
{
	double	percent_x;
	double	percent_y;

	percent_x = (e->x2 - e->x1) / 2;
	percent_y = (e->y2 - e->y1) / 2;
	if (keycode == 116)
	{
		e->x1 += percent_x * (e->p_x / WIN_W);
		e->x2 -= percent_x * (1 - e->p_x / WIN_W);
		e->y1 += percent_y * (e->p_y / WIN_H);
		e->y2 -= percent_y * (1 - e->p_y / WIN_H);
	}
	if (keycode == 121)
	{
		e->x1 -= percent_x * (e->p_x / WIN_W);
		e->x2 += percent_x * (1 - e->p_x / WIN_W);
		e->y1 -= percent_y * (e->p_y / WIN_H);
		e->y2 += percent_y * (1 - e->p_y / WIN_H);
	}
}

int			keyhook(int keycode, t_env *e)
{
	mlx_clear_set_image(e);
	if (keycode == 53)
	{
		mlx_destroy_image(e->mlx, e->img);
		mlx_clear_window(e->mlx, e->win);
		exit(0);
	}
	if (keycode == 49)
		e->pause = (e->pause == 0 ? 1 : 0);
	if (keycode == 8)
		e->color++;
	if (keycode == 15)
		fractal_init(e);
	if (keycode == 116 || keycode == 121)
		zoom(keycode, e);
	if (keycode == 69 || keycode == 78)
		iteration(keycode, e);
	if (keycode == 124 || keycode == 123 ||
	keycode == 125 || keycode == 126)
		move_arrow(keycode, e);
	if (keycode == 46)
		e->menu = e->menu == 0 ? 1 : 0;
	expose(e);
	return (0);
}
