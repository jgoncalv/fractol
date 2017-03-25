/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:20:23 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/15 16:20:24 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define USAGE "USAGE : ./fractol <fractal>\nmandelbrot / julia\n"
# define WIN_H 500
# define WIN_W 500
# define LIMIT_MAX 10000
# define LIMIT_MIN -10000

# include <mlx.h>
# include "libft.h"
# include </System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h>

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			id;
	double		p_coefx;
	double		p_coefy;
	int			iteration;
	double		color;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		p_x;
	double		p_y;
	int			pause;
	int			menu;
}				t_env;

typedef struct	s_calc
{
	int			i;
	int			i_max;
	double		x;
	double		y;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
	double		zoom_x;
	double		zoom_y;
}				t_calc;

void			fractal(int id);
void			mlx_image(t_env *e);
int				expose(t_env *e);
void			mlx_clear_set_image(t_env *e);
void			fill_pixel(char **img, int x, int y, int color);
int				keyhook(int keycode, t_env *e);
void			mandelbrot(t_env *e);
void			julia(t_env *e);
int				pointerhook(int x, int y, t_env *e);
void			fractal_init(t_env *e);
int				mousehook(int mousecode, int x, int y, t_env *e);

#endif
