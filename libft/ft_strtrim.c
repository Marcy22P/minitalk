/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:43:06 by mpisani           #+#    #+#             */
/*   Updated: 2024/12/16 11:43:08 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*output;
	int		i;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] != '\0' && check_set(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= start && check_set(s1[end], set))
		end--;
	output = malloc((end - start + 2) * sizeof(char));
	if (!output)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		output[i++] = s1[start++];
	}
	output[i] = '\0';
	return (output);
}
