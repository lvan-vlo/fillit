/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map_tetriminos.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/13 16:44:39 by twoerdem       #+#    #+#                */
/*   Updated: 2019/02/25 18:33:25 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_trim_top(char **array)
{
	char	**ret;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (ft_strchr(array[y], '#') == NULL)
		y++;
	ret = ft_memalloc(sizeof(char*) * ft_set_y(array) - y + 1);
	while (array[y])
	{
		ret[i] = ft_strdup(array[y]);
		i++;
		y++;
	}
	ret[i] = NULL;
	ft_delmap(array);
	return (ret);
}

char	**ft_trim_left(char **array)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (x < (int)ft_strlen(array[0]))
	{
		if (ft_strchr_y(array, x, '#') == NULL)
		{
			while (array[y] != NULL)
			{
				ft_memmove(array[y], array[y] + 1, ft_strlen(array[y]));
				y++;
			}
		}
		else
			break ;
		y = 0;
	}
	array = ft_trim_top(array);
	return (array);
}

char	**ft_trim_bot(char **array)
{
	int		y;

	y = 0;
	while (array[y] != NULL)
		y++;
	y--;
	while (y >= 0)
	{
		if (ft_strchr(array[y], '#') == NULL)
		{
			free(array[y]);
			array[y] = NULL;
			y--;
		}
		else
			break ;
	}
	array = ft_trim_left(array);
	return (array);
}

char	**ft_make_tet(char *file)
{
	char	**array;
	int		y;
	int		x;

	y = 0;
	x = 3;
	array = ft_strsplit(file, '\n');
	while (x >= 0)
	{
		if (ft_strchr_y(array, x, '#') == NULL)
		{
			while (y < 4)
			{
				array[y][x] = '\0';
				y++;
			}
		}
		else
			break ;
		y = 0;
		x--;
	}
	array = ft_trim_bot(array);
	free(file);
	return (array);
}
