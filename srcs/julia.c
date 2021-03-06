/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:25:25 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/15 19:25:26 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	julia_norme(t_calc *cc, t_env *e)
{
	while (cc->z_r * cc->z_r + cc->z_i * cc->z_i < 4 && cc->i < cc->i_max)
	{
		cc->tmp = cc->z_r;
		cc->z_r = cc->z_r * cc->z_r - cc->z_i * cc->z_i + cc->c_r;
		cc->z_i = 2 * cc->z_i * cc->tmp + cc->c_i;
		cc->i++;
	}
	if (cc->i == cc->i_max)
		fill_pixel(&e->data, cc->x, cc->y, 0);
	else
		fill_pixel(&e->data, cc->x, cc->y,
			0xE8B71A * (e->color / (double)cc->i));
}

void		julia(t_env *e)
{
	t_calc	cc;

	cc.i_max = 50 + e->iteration;
	cc.zoom_x = WIN_W / (e->x2 - e->x1);
	cc.zoom_y = WIN_H / (e->y2 - e->y1);
	cc.x = 0;
	while (cc.x < WIN_W)
	{
		cc.y = 0;
		while (cc.y < WIN_H)
		{
			cc.c_r = 0.285 + e->p_coefx;
			cc.c_i = 0.01 + e->p_coefy;
			cc.z_r = (cc.x / cc.zoom_x + e->x1);
			cc.z_i = (cc.y / cc.zoom_y + e->y1);
			cc.i = 0;
			julia_norme(&cc, e);
			cc.y++;
		}
		cc.x++;
	}
}
