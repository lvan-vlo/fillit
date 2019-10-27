/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: twoerdem <twoerdem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 09:15:01 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/02/25 16:29:45 by twoerdem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*p;
	void	*array;
	size_t	c;

	c = 0;
	array = malloc(size);
	if (array == NULL)
		return (NULL);
	p = (char*)array;
	while (c < size)
	{
		p[c] = '\0';
		c++;
	}
	return (array);
}
