/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:49:36 by mpisani           #+#    #+#             */
/*   Updated: 2025/01/20 15:15:13 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_base_10(long n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
		count += ft_print_base_10(n / 10);
	c = n % 10 + '0';
	count += write(1, &c, 1);
	return (count);
}

int	print_decimal(int n)
{
	long	num;
	int		count;

	num = (long)n;
	count = 0;
	if (num < 0)
	{
		count += write(1, "-", 1);
		num = -num;
	}
	count += ft_print_base_10(num);
	return (count);
}

int	print_unsigned(unsigned int n)
{
	int		count;
	long	num;

	num = (long)n;
	count = 0;
	count += ft_print_base_10(num);
	return (count);
}
