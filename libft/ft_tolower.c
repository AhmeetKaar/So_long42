/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:06:37 by akar              #+#    #+#             */
/*   Updated: 2023/12/25 15:16:19 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	str;

	if (c >= 65 && c <= 90)
	{
		str = (unsigned char)c;
		str += 32;
		return (str);
	}
	return (c);
}
