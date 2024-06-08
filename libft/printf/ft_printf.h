/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:46:34 by akar              #+#    #+#             */
/*   Updated: 2024/01/11 15:46:34 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	control(va_list args, const char format);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(long value);
int	ft_hex(unsigned long long value, char *hexchar);

#endif
