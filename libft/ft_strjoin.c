/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 16:58:20 by akar              #+#    #+#             */
/*   Updated: 2023/12/25 16:58:20 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	lens1;
	size_t	lens2;

	i = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (str == NULL)
		return (NULL);
	while (i < lens1)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < lens2)
	{
		str[lens1 + i] = s2[i];
		i++;
	}
	str[lens1 + lens2] = '\0';
	return (str);
}
