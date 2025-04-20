/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:50:48 by mpisani           #+#    #+#             */
/*   Updated: 2025/01/19 23:09:40 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sort_printf(char c, va_list *args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(*args, int)));
	else if (c == 's')
		return (ft_print_string(va_arg(*args, char *)));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(*args, void *)));
	else if (c == 'd' || c == 'i')
		return (print_decimal(va_arg(*args, int)));
	else if (c == 'u')
		return (print_unsigned(va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (ft_print_hex(va_arg(*args, unsigned int), 0));
	else if (c == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), 1));
	else if (c == '%')
		return (ft_print_percent());
	return (0);
}
