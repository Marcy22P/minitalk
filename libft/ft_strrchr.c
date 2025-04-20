/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:43:01 by mpisani           #+#    #+#             */
/*   Updated: 2024/12/17 11:33:14 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*itemp;

	i = 0;
	itemp = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			itemp = (&(((char *)s)[i]));
		}
		i++;
	}
	if (c == '\0')
		return (&(((char *)s)[i]));
	else
		return (itemp);
}
