/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 14:17:16 by lvan-vlo      #+#    #+#                 */
/*   Updated: 2019/01/20 16:55:17 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fillarray(unsigned char *src, char *array, unsigned char c, int ac)
{
	int x;
	int w;
	int i;

	x = 0;
	w = 0;
	i = 0;
	while (w < ac)
	{
		while (src[i] == c)
			i++;
		if (src[i] != c && src[i] != '\0')
			w++;
		while (src[i] != c && src[i] != '\0')
			i++;
	}
	while (src[i] == c)
		i++;
	while (src[i] != c && src[i] != '\0')
	{
		array[x] = src[i];
		i++;
		x++;
	}
	return (array);
}

static int	charcount(unsigned char *src, unsigned char c, int ac)
{
	int x;
	int w;
	int i;

	x = 0;
	w = 0;
	i = 0;
	while (w < ac)
	{
		while (src[i] == c)
			i++;
		if (src[i] != c && src[i] != '\0')
			w++;
		while (src[i] != c && src[i] != '\0')
			i++;
	}
	while (src[i] == c)
		i++;
	while (src[i] != c && src[i] != '\0')
	{
		i++;
		x++;
	}
	return (x - 1);
}

static int	wordcount(unsigned char *src, unsigned char c)
{
	int	w;
	int i;

	w = 0;
	i = 0;
	while (src[i] != '\0')
	{
		while (src[i] == c)
			i++;
		if (src[i] != c && src[i] != '\0')
			w++;
		while (src[i] != c && src[i] != '\0')
			i++;
	}
	return (w);
}

char		**ft_strsplit(char const *s, char c)
{
	char			**array;
	unsigned char	*src;
	unsigned char	l;
	int				ac;
	int				w;

	src = (unsigned char*)s;
	l = (unsigned char)c;
	ac = 0;
	w = wordcount(src, l);
	if (!(array = malloc(sizeof(char*) * w + 1)))
		return (NULL);
	while (ac < w)
	{
		if (!(array[ac] = malloc(sizeof(char) * (charcount(src, l, ac)))))
			return (NULL);
		array[ac] = fillarray(src, array[ac], l, ac);
		ac++;
	}
	array[ac] = NULL;
	return (array);
}
