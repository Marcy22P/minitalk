/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:08:01 by mpisani           #+#    #+#             */
/*   Updated: 2024/12/20 11:20:42 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_size;
	size_t			i;
	unsigned char	*falloc;

	i = 0;
	total_size = nmemb * size;
	if (size != 0 && total_size / size != nmemb)
		return (NULL);
	falloc = malloc(total_size);
	if (!falloc)
		return (NULL);
	while (i < total_size)
	{
		((unsigned char *)falloc)[i] = 0;
		i++;
	}
	return (falloc);
}
