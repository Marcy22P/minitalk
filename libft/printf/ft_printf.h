/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpisani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:51:19 by mpisani           #+#    #+#             */
/*   Updated: 2025/01/19 22:41:21 by mpisani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_print_char(int c);
int	ft_print_hex(unsigned int n, int upper);
int	print_decimal(int n);
int	print_unsigned(unsigned int n);
int	ft_print_percent(void);
int	ft_print_ptr(void *ptr);
int	ft_print_string(const char *s);
int	ft_printf(const char *format, ...);
int	ft_sort_printf(char c, va_list *args);

#endif