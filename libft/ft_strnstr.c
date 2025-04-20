/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:42:53 by mpisani           #+#    #+#             */
/*   Updated: 2024/12/20 10:27:19 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)&str[i]);
	if (n == 0)
		return (NULL);
	while (i < n && str[i] != '\0')
	{
		j = 0;
		while (i + j < n && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char *haystack = "Hello, 42 ziopera";
// 	const char *needle1 = "42";
// 	const char *needle2 = "ziopera";

// 	size_t len = 18;

// 	printf("1: %s\n", ft_strnstr(haystack, needle1, len));

// 	printf("2: %s\n", ft_strnstr(haystack, needle2, len));
// 	return (0);
// }