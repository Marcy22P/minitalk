/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:42:01 by mpisani           #+#    #+#             */
/*   Updated: 2024/12/23 14:36:41 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*conc;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	conc = malloc((i + j + 1) * sizeof(char));
	if (!conc)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		conc[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		conc[i + j] = s2[j];
		j++;
	}
	conc[i + j] = '\0';
	return (conc);
}
