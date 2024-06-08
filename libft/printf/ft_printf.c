/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:18:02 by akar              #+#    #+#             */
/*   Updated: 2024/01/11 15:18:02 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	return (i);
}

int	control(va_list args, const char format)
{
	int	value;

	value = 0;
	if (format == 'd' || format == 'i')
		value += ft_putnbr(va_arg(args, int));
	else if (format == 's')
		value += ft_putstr(va_arg(args, char *));
	else if (format == 'c')
		value += ft_putchar(va_arg(args, int));
	else if (format == 'X')
		value += ft_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format == 'x')
		value += ft_hex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'u')
		value += ft_putnbr(va_arg(args, unsigned int));
	else if (format == 'p')
	{
		value += write(1, "0x", 2);
		value += ft_hex(va_arg(args, unsigned long long), "0123456789abcdef");
	}
	else if (format == '%')
		value += ft_putchar('%');
	return (value);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		return_value;
	va_list	args;

	i = 0;
	return_value = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			return_value += control(args, format[i + 1]);
			i++;
		}
		else
			return_value += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (return_value);
}
