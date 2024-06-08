/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:57:47 by akar              #+#    #+#             */
/*   Updated: 2024/01/05 21:00:19 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long value)
{
	int	i;

	i = 0;
	if (value == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (value < 0)
	{
		write(1, "-", 1);
		i++;
		value = -value;
	}
	if (value > 9)
	{
		i += ft_putnbr(value / 10);
		i += ft_putnbr(value % 10);
	}
	else
		i += ft_putchar(value + 48);
	return (i);
}

int	ft_hex(unsigned long long value, char *hexchar)
{
	int	i;

	i = 0;
	if (value >= 16)
	{
		i += ft_hex(value / 16, hexchar);
		i += ft_hex(value % 16, hexchar);
	}
	else
	{
		i += write(1, &hexchar[value], 1);
	}
	return (i);
}
