/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:42:08 by mpisani           #+#    #+#             */
/*   Updated: 2024/12/20 17:14:05 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_s;
	size_t	len_d;
	size_t	i;

	len_s = 0;
	len_d = 0;
	i = 0;
	while (src[len_s] != '\0')
		len_s++;
	while (len_d < size && dst[len_d] != '\0')
		len_d++;
	if (size <= len_d)
		return (size + len_s);
	while (i < size - len_d - 1 && src[i] != '\0')
	{
		dst[len_d + i] = src[i];
		i++;
	}
	if (len_d + i < size)
		dst[len_d + i] = '\0';
	return (len_d + len_s);
}
