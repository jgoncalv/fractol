/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:16:20 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/02/08 15:21:43 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_atoi_tab(char **tab)
{
	int	*res;
	int	len;

	len = ft_tablen(tab);
	res = (int*)malloc(sizeof(int) * len);
	len--;
	while (len >= 0)
	{
		res[len] = ft_atoi(tab[len]);
		len--;
	}
	return (res);
}
