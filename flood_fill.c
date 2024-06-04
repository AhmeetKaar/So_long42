/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:18:56 by akar              #+#    #+#             */
/*   Updated: 2024/06/04 12:18:56 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	f_fill(char **tab, t_location mapsize, int y, int x);
static void	flf_check(t_game *so_long);
static int	ft_strchr_gnl(char *str, int c);

void	flood_fill(t_game *so_long)
{
	t_location	chatr;
	t_location	mapsize;

	so_long->mapcopy = get_map(so_long);
	chatr.x = so_long->chrx;
	chatr.y = so_long->chry;
	mapsize.x = so_long->mapx;
	mapsize.y = so_long->mapy;
	f_fill(so_long->mapcopy, mapsize, chatr.y, chatr.x);
	flf_check(so_long);
	free_map(so_long, 2);
}

static void	f_fill(char **tab, t_location mapsize, int y, int x)
{
	if (y < 0 || x < 0)
		return ;
	if (y >= mapsize.y || x >= mapsize.x)
		return ;
	if (tab[y][x] == 'Z' || tab[y][x] == '1')
		return ;
	tab[y][x] = 'Z';
	f_fill(tab, mapsize, y - 1, x);
	f_fill(tab, mapsize, y + 1, x);
	f_fill(tab, mapsize, y, x - 1);
	f_fill(tab, mapsize, y, x + 1);
}

static void	flf_check(t_game *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (so_long->mapcopy[i])
	{
		j = 0;
		while (so_long->mapcopy[i][j])
		{
			if (ft_strchr_gnl("PEC", so_long->mapcopy[i][j]))
			{
				ft_printf("Error: For flood fill");
				free_map(so_long, 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

static int	ft_strchr_gnl(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
