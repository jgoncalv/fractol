/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 23:42:17 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/05 23:42:19 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabdel(char **tab, size_t size)
{
	size_t	i;

	i = 0;
	if (tab)
	{
		while (i++ < size)
			ft_strdel(&tab[i]);
		free(tab);
		tab = NULL;
	}
}
