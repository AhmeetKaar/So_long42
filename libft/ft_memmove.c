/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:45:09 by akar              #+#    #+#             */
/*   Updated: 2023/12/25 17:28:57 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*src2;

	dest = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (dst > src)
	{
		while (len)
		{
			dest[len - 1] = src2[len - 1];
			len--;
		}
		return (dst);
	}
	return (ft_memcpy(dst, src, len));
}
