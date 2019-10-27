/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frees.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/22 15:16:17 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/02/25 18:33:26 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_delmap(char **map)
{
	int y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
}

void	ft_del_tetri(t_tetris *head)
{
	t_tetris	*cur;

	cur = head;
	while (cur)
	{
		ft_delmap(cur->content);
		head = cur;
		cur = cur->next;
		free(head);
	}
}

char	**ft_map_make(int mapsize)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char*) * mapsize + 1);
	map[mapsize] = NULL;
	while (i < mapsize)
	{
		map[i] = malloc(sizeof(char) * mapsize + 1);
		map[i][mapsize] = '\0';
		ft_memset(map[i], '.', mapsize);
		i++;
	}
	return (map);
}
