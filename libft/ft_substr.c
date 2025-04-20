/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:43:13 by mpisani           #+#    #+#             */
/*   Updated: 2024/12/20 17:30:04 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	len2;
	char	*substr;

	len2 = 0;
	if ((int)start >= ft_strlen(s) || !s)
		return (ft_strdup(""));
	if (start > (long long int)ft_strlen(s))
		return (NULL);
	while (s[start + len2] != '\0' && len2 < len)
		len2++;
	substr = (char *)malloc((len2 + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len2 + 1);
	return (substr);
}
