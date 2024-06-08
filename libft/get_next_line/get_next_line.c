/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:49:20 by akar              #+#    #+#             */
/*   Updated: 2024/05/17 21:08:21 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readline_gnl(int fd, char *dst)
{
	int		i;
	char	*buff;

	i = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (i != 0 && !control_gnl(dst, '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(dst);
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		dst = ft_strjoin_gnl(dst, buff);
	}
	free(buff);
	return (dst);
}

char	*ft_getline_gnl(char *dst)
{
	int		i;
	int		x;
	char	*line;

	i = 0;
	x = 0;
	if (!dst[i])
		return (NULL);
	while (dst[i] && dst[i] != '\n')
		i++;
	if (dst[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (x < i)
	{
		line[x] = dst[x];
		x++;
	}
	line[x] = '\0';
	return (line);
}

char	*ft_get_left_gnl(char *dst)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	while (dst[i] && dst[i] != '\n')
		i++;
	if (!dst[i])
	{
		free(dst);
		return (NULL);
	}
	if (dst[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (ft_strlen_gnl(dst) - i + 1));
	if (!str)
		return (NULL);
	while (dst[i])
		str[len++] = dst[i++];
	str[len] = '\0';
	free(dst);
	return (str);
}

char	*get_next_line_gnl(int fd)
{
	static char	*dst;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	dst = ft_readline_gnl(fd, dst);
	if (!dst)
		return (NULL);
	str = ft_getline_gnl(dst);
	dst = ft_get_left_gnl(dst);
	return (str);
}
