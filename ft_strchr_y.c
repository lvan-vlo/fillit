/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr_y.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: twoerdem <twoerdem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 16:27:07 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/02/25 14:44:16 by twoerdem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strchr_y(char **array, int x, char c)
{
	int		y;

	y = 0;
	while (array[y] != NULL)
	{
		if (array[y][x] == c)
			return (array[y]);
		y++;
	}
	return (NULL);
}

char	**replace_character(char **array, int c)
{
	int		x;
	int		y;

	y = 0;
	while (array[y])
	{
		x = 0;
		while (array[y][x])
		{
			if (array[y][x] == '#')
				array[y][x] = c;
			x++;
		}
		y++;
	}
	return (array);
}
