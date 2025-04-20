/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:42:41 by mpisani           #+#    #+#             */
/*   Updated: 2024/12/17 11:39:51 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str_return;

	i = 0;
	if (!s || !f)
		return (malloc(0));
	str_return = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str_return)
		return (NULL);
	while (s[i])
	{
		str_return[i] = f(i, s[i]);
		i++;
	}
	str_return[i] = '\0';
	return (str_return);
}
