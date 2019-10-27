/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_file.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 13:26:44 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/02/25 15:55:38 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_brothers(char *file)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (i < 20)
	{
		if (file[i] == '#')
		{
			if (file[i - 1] == '#' && i - 1 >= 0)
				ret++;
			if (file[i + 1] == '#' && i + 1 <= 20)
				ret++;
			if (file[i - 5] == '#' && i - 5 >= 0)
				ret++;
			if (file[i + 5] == '#' && i + 5 <= 20)
				ret++;
		}
		i++;
	}
	free(file);
	if (ret == 6 || ret == 8)
		return (1);
	return (0);
}

int		ft_ncount(char *p)
{
	int ret;

	ret = 0;
	if (p[4] == '\n')
		ret++;
	if (p[9] == '\n')
		ret++;
	if (p[14] == '\n')
		ret++;
	if (p[19] == '\n')
		ret++;
	return (ret);
}

int		ft_charcount(char *p, char c, int len)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (i < len)
	{
		if (p[i] == c)
			x++;
		i++;
	}
	return (x);
}

int		ft_basic_check(char *p)
{
	if (ft_charcount(p, '.', 20) != 12)
		return (0);
	if (ft_charcount(p, '#', 20) != 4)
		return (0);
	if (ft_ncount(p) != 4)
		return (0);
	return (1);
}

int		ft_check_file(char *file)
{
	char	*p;
	int		ret;
	int		len;

	len = ft_strlen(file);
	p = file;
	if (ft_strlen(p) > 545 || ft_strlen(p) < 20)
		return (0);
	if (check_brothers(ft_strsub(p, 0, 20)) == 0)
		return (0);
	if (ft_basic_check(p) == 0)
		return (0);
	if (ft_strlen(p) > 20)
	{
		p = ft_strstr(p, "\n\n");
		if (p == NULL)
		{
			return (0);
		}
		p = p + 2;
		ret = ft_check_file(p);
		return (ret);
	}
	return (1);
}
