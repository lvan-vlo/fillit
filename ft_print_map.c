/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/16 15:16:29 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/02/20 20:03:19 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_putendl(map[i]);
		i++;
	}
}
