/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 15:37:11 by lvan-vlo      #+#    #+#                 */
/*   Updated: 2019/01/13 15:40:38 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int	c;

	c = 0;
	while (s[c] != '\0')
	{
		write(1, &s[c], 1);
		c++;
	}
	write(1, "\n", 1);
}
