/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:22:06 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/03/15 16:22:07 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_fractal_name(char *str)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		return (1);
	if (ft_strcmp(str, "julia") == 0)
		return (2);
	return (0);
}

static void	multi_win(int ac, char **av)
{
	int	pid;
	int	ret;
	int	i;

	i = 1;
	while (i <= ac)
	{
		if ((pid = fork()) == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (!(ret = check_fractal_name(av[i])))
			{
				ft_putstr_fd("Error : Unknown fractal name\n", 2);
				exit(1);
			}
			fractal(ret);
			exit(0);
		}
		i++;
	}
}

int			main(int ac, char **av)
{
	if (ac > 1)
	{
		multi_win(ac, av);
		while (wait(NULL) != -1)
			;
		if (errno != ECHILD)
		{
			perror(NULL);
			return (1);
		}
	}
	else
		ft_putstr(USAGE);
	return (0);
}
