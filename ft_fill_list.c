/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fill_list.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/16 16:49:52 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/02/25 18:33:22 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_set_y(char **tetris)
{
	int			i;

	i = 0;
	while (tetris[i])
		i++;
	return (i);
}

void		ft_fill_list(char *file)
{
	t_tetris	*head;
	t_tetris	*cur;
	char		*tmp;
	char		c;

	head = ft_memalloc(sizeof(t_tetris));
	cur = head;
	c = 'A';
	while ((ft_strlen(file) + 1) / 21 > 0 && file)
	{
		tmp = ft_strsub(file, 0, 20);
		cur->content = replace_character(ft_make_tet(tmp), c);
		cur->y = ft_set_y(cur->content);
		cur->x = ft_strlen(cur->content[0]);
		if (ft_strlen(file) < 21)
			break ;
		cur->next = ft_memalloc(sizeof(t_tetris));
		cur = cur->next;
		ft_memmove(file, file + 21, ft_strlen(file));
		c++;
	}
	cur->next = NULL;
	ft_fillit(head, 2);
}
