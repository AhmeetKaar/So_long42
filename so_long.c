/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:54:58 by akar              #+#    #+#             */
/*   Updated: 2024/06/01 21:39:03 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static void last_newline(char *tmp)
{
    int i;

    i = ft_strlen(tmp) - 1;
    if (tmp[i] == '\n')
    {
        free(tmp);
        ft_printf("bk gibi map");
        exit(-1);
    }
}

int countline(char *ber)
{
    char *str;
    char *tmp = NULL;
    int i;
    int fd;

    fd = open(ber, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Error: Failed to open file\n");
        return -1;
    }

    i = 0;
    while ((str = get_next_line_gnl(fd)) != NULL)
    {
        if (tmp != NULL)
            free(tmp);
        tmp = str;
        i++;
    }

    if (tmp != NULL)	
    {
        last_newline(tmp);
        free(tmp);
    }

    close(fd);
    return i;
}

char	**get_map(t_game *so_long)
{
	int		i;
	int		fd;
	char	**str;

	fd = open(so_long->mapname, O_RDONLY);
	str = malloc(sizeof(char *) * so_long->mapy + 1);
	close(fd);
	fd = open(so_long->mapname, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: File not open.");
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
	return (str);
}

void	free_map(t_game *so_long, int n)
{
	int	i;

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
