/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointerhook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 21:28:35 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/15 21:28:36 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	pointerhook(int x, int y, t_env *e)
{
	e->p_x = x;
	e->p_y = y;
	if (x >= 0 && y >= 0 && x < WIN_W && y < WIN_H
		&& e->pause == 0)
	{
		mlx_clear_set_image(e);
		e->p_coefx = ((double)x - WIN_W / 2) / WIN_W / 2;
		e->p_coefy = ((double)y - WIN_W / 2) / WIN_H / 2;
		expose(e);
	}
	return (0);
}
