/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:49:32 by akar              #+#    #+#             */
/*   Updated: 2024/06/04 14:34:11 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	control_gnl(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *dst, char *src)
{
	char	*allocated;
	int		i;
	int		x;

	allocated = malloc(sizeof(char) * (ft_strlen_gnl(dst) + ft_strlen_gnl(src)
				+ 1));
	if (!allocated)
		return (NULL);
	i = 0;
	x = 0;
	if (!dst)
	{
		dst = malloc(sizeof(char));
		if (!dst)
			return (NULL);
		dst[0] = '\0';
	}
	while (dst[i])
		allocated[x++] = dst[i++];
	i = 0;
	while (src[i])
		allocated[x++] = src[i++];
	allocated[x] = '\0';
	free(dst);
	return (allocated);
}
