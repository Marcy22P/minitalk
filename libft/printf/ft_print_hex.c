/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:49:13 by mpisani           #+#    #+#             */
/*   Updated: 2025/01/20 15:16:47 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_hex_recursive(unsigned int n, int upper)
{
	char	*base_lower;
	char	*base_upper;
	int		count;

	base_lower = "0123456789abcdef";
	base_upper = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_print_hex_recursive(n / 16, upper);
	if (upper)
		count += write(1, &base_upper[n % 16], 1);
	else
		count += write(1, &base_lower[n % 16], 1);
	return (count);
}

int	ft_print_hex(unsigned int n, int upper)
{
	int	count;

	count = 0;
	if (n == 0)
		return (write(1, "0", 1));
	count += ft_print_hex_recursive(n, upper);
	return (count);
}
