/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fillit.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 16:16:01 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/02/25 18:33:49 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_make_map(t_tetris *cur, char **map, int y, int x)
{
	int		ysave;
	int		xsave;
	int		mapy;
	int		mapx;

	ysave = cur->y;
	xsave = cur->x;
	mapy = y + cur->y - 1;
	mapx = x + cur->x - 1;
	while (cur->y > 0)
	{
		while (cur->x > 0)
		{
			if (cur->content[cur->y - 1][cur->x - 1] != '.')
				map[mapy][mapx] = cur->content[cur->y - 1][cur->x - 1];
			mapx--;
			cur->x--;
		}
		cur->x = xsave;
		mapx = x + cur->x - 1;
		mapy--;
		cur->y--;
	}
	cur->y = ysave;
	return (map);
}

void	ft_clear_map(t_tetris *cur, char **map)
{
	int c;
	int y;
	int x;

	x = 0;
	while (cur->content[0][x] == '.')
	{
		x++;
	}
	c = cur->content[0][x];
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
}

int		ft_check_pos(t_tetris *cur, char **map, int y, int x)
{
	int		ys;
	int		xs;
	int		mapx;

	ys = (int)cur->y;
	xs = (int)cur->x;
	y += (int)cur->y - 1;
	mapx = x + (int)cur->x - 1;
	if (mapx > (int)ft_strlen(map[0]) - 1 || y > (int)ft_strlen(map[0]) - 1)
		return (0);
	while (ys > 0)
	{
		while (xs > 0)
		{
			if (cur->content[ys - 1][xs - 1] != '.' && map[y][mapx] != '.')
				return (0);
			mapx--;
			xs--;
		}
		xs = (int)cur->x;
		mapx = x + (int)cur->x - 1;
		y--;
		ys--;
	}
	return (1);
}

int		ft_loop_tet(t_tetris *cur, char **map)
{
	int		pos;
	int		ms;

	pos = 0;
	ms = ft_strlen(map[0]);
	if ((int)cur->y > ms || (int)cur->x > ms)
		return (0);
	while (pos < ms * ms)
	{
		if (ft_check_pos(cur, map, pos / ms, pos % ms) == 1)
		{
			map = ft_make_map(cur, map, pos / ms, pos % ms);
			if (cur->next && ft_loop_tet(cur->next, map) == 1)
			{
				return (1);
			}
			else if (!(cur->next))
				return (1);
			ft_clear_map(cur, map);
		}
		pos++;
	}
	return (0);
}

void	ft_fillit(t_tetris *head, int mapsize)
{
	char	**map;
	int		i;

	i = 0;
	while (head)
	{
		map = ft_map_make(mapsize);
		if (ft_loop_tet(head, map) == 1)
		{
			ft_print_map(map);
			ft_del_tetri(head);
			ft_delmap(map);
			break ;
		}
		ft_delmap(map);
		mapsize++;
	}
}
