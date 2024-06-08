/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:43:13 by akar              #+#    #+#             */
/*   Updated: 2023/12/25 18:43:13 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_step(int x)
{
	int	countstep;

	countstep = 0;
	if (x == 0)
		return (1);
	if (x < 0)
	{
		x *= -1;
		countstep++;
	}
	while (x > 0)
	{
		x /= 10;
		countstep++;
	}
	return (countstep);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_step(n);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[len--] = '\0';
	while (n > 0)
	{
		str[len] = '0' + (n % 10);
		n /= 10;
		len--;
	}
	return (str);
}
