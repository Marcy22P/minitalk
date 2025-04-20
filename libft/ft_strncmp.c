/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:42:46 by mpisani           #+#    #+#             */
/*   Updated: 2024/12/17 11:37:30 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n && str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	if (i < n)
		return (str1[i] - str2[i]);
	return (0);
}

// int	main(void)
// {
//     printf("Test1: %d\n", ft_strncmp("Hello", "Hello", 5));
// s1 ed str2 zio pera identiche
//     printf("Test2: %d\n", ft_strncmp("Hello", "Helmo", 5));
// str2 diversa da s1 (più grande)
//     printf("Test3: %d\n", ft_strncmp("Heo", "Hello", 4));
// s1 più piccolina rispetto ad s2
//     printf("Test4: %d\n", ft_strncmp("Hello", "Hello", 10));
// size_t n più grande delle stringhe

// 	return (0);
// }