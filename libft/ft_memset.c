/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:53:05 by akar              #+#    #+#             */
/*   Updated: 2023/12/25 18:36:08 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s1;

	s1 = (unsigned char *)b;
	while (len > 0)
	{
		*s1 = (unsigned char)c;
		s1++;
		len--;
	}
	return (b);
}
