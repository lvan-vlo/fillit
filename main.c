/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 15:53:12 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/02/26 15:57:47 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char		*file;
	int			fd;
	int			ret;

	file = ft_strnew(1);
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		file = ft_read_tetriminos(fd, file);
		if (file == NULL)
			return (0);
		ret = ft_check_file(file);
		if (ret == 0)
		{
			ft_putendl("error");
			return (0);
		}
		ft_fill_list(file);
		free(file);
		close(fd);
	}
	else
		ft_putendl("usage: ./fillit input_file");
	return (0);
}
