/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:36:13 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/25 17:36:14 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mousehook(int mousecode, int x, int y, t_env *e)
{
	double	percent_x;
	double	percent_y;

	(void)x;
	(void)y;
	percent_x = (e->x2 - e->x1) / 2;
	percent_y = (e->y2 - e->y1) / 2;
	mlx_clear_set_image(e);
	if (mousecode == 4)
	{
		e->x1 += percent_x * (e->p_x / WIN_W);
		e->x2 -= percent_x * (1 - e->p_x / WIN_W);
		e->y1 += percent_y * (e->p_y / WIN_H);
		e->y2 -= percent_y * (1 - e->p_y / WIN_H);
	}
	if (mousecode == 5)
	{
		e->x1 -= percent_x * (e->p_x / WIN_W);
		e->x2 += percent_x * (1 - e->p_x / WIN_W);
		e->y1 -= percent_y * (e->p_y / WIN_H);
		e->y2 += percent_y * (1 - e->p_y / WIN_H);
	}
	expose(e);
	return (0);
}
