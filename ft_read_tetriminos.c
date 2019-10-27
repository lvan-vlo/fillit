/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_tetriminos.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 13:14:36 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/02/25 18:33:24 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_read_tetriminos(int fd, char *file)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret < 0)
			return (NULL);
		buf[ret] = '\0';
		tmp = ft_strjoin(file, buf);
		free(file);
		file = ft_strdup(tmp);
		free(tmp);
	}
	return (file);
}
