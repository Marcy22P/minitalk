/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:58:50 by mpisani           #+#    #+#             */
/*   Updated: 2025/01/17 18:09:02 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_hex_rec(unsigned long num)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (num >= 16)
		count = count + ft_print_hex_rec(num / 16);
	count = count + write(1, &base[num % 16], 1);
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long	address;
	int				count;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = 0;
	address = (unsigned long long)ptr;
	count = count + write(1, "0x", 2);
	if (address == 0)
		count = count + write(1, "0", 1);
	else
		count = count + ft_print_hex_rec(address);
	return (count);
}
