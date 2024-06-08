/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:19:49 by akar              #+#    #+#             */
/*   Updated: 2023/12/25 16:27:10 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	x;
	unsigned char	*str;

	i = 0;
	x = (unsigned char)c;
	str = (unsigned char *)s;
	while (n > 0)
	{
		if (str[i] == x)
			return (&str[i]);
		i++;
		n--;
	}
	return (NULL);
}
