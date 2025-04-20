/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:41:03 by mpisani           #+#    #+#             */
/*   Updated: 2024/12/17 11:26:14 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*bstr1;
	unsigned char	*bstr2;

	i = 0;
	bstr1 = ((unsigned char *)s1);
	bstr2 = ((unsigned char *)s2);
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (bstr1[i] != bstr2[i])
		{
			return (bstr1[i] - bstr2[i]);
		}
		i++;
	}
	return (0);
}
