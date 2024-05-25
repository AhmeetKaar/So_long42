/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:54:58 by akar              #+#    #+#             */
/*   Updated: 2024/05/25 17:21:27 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int countline(char *ber)
{
	char *str;
	int i;
	int fd;

	fd = open(ber,O_RDONLY);
	str = malloc(sizeof(char) * 1);

	i = -1;
	str[0] = 'a';
	while (str)
	{
		free(str);
		str = get_next_line_gnl(fd);
		i++;
	}
	return(i);
}

char **get_map(t_game *so_long)
{
	int i;
	int fd;
	char **str;
	
	
	fd = open(so_long->mapname,O_RDONLY);
	str = malloc(sizeof(char *) * so_long->mapy + 1);
	close(fd);	
	fd = open(so_long->mapname,O_RDONLY);
	if(fd == -1)
	{
		ft_printf("Ber file couldn't be opened");
		free(str);
		exit(1);
	}
	i = 0;
	while (i < so_long->mapy)
	{
		str[i] = get_next_line_gnl(fd);
		i++;
	}
	str[i] = NULL;
	so_long->mapx = strlen_newline(str[0]);
	return(str);
}

void free_map(t_game *so_long,int n)
{
	int i;

	i = 0;

	if (n == 1)
	{
		while (i < so_long->mapy)
		{
			free(so_long->map[i]);
			i++;
		}
		free(so_long->map);
	}
	else
	{
		while (i < so_long->mapy)
		{
			free(so_long->mapcopy[i]);
			i++;
		}
		free(so_long->mapcopy);
	}
}
	
