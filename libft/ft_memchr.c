/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:40:54 by mpisani           #+#    #+#             */
/*   Updated: 2024/12/17 11:34:37 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	d;
	unsigned char	*t;

	d = (unsigned char)c;
	t = ((unsigned char *)s);
	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (t[i] == d)
		{
			return ((void *)&t[i]);
		}
		i++;
	}
	return (NULL);
}
