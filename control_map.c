/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:52:37 by akar              #+#    #+#             */
/*   Updated: 2024/06/03 18:34:19 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void count_check(t_game *so_long)
{
	if (so_long->e_count != 1)
	{
		ft_printf("Error: There is more than one exit.");
		exit(1);
	}
	else if (so_long->c_count < 1)
	{
		ft_printf("Error: No items to collect");
		exit(1);
	}
	else if (so_long->p_count != 1)
	{
		ft_printf("Error: There is more than one player.");
		exit(1);
	}
}

void get_location(t_game *so_long, int x, int y)
{
	y = 0;
	while (y < so_long->mapy)
	{
		x = 0;
		while (x < so_long->mapx)
		{
			if (so_long->map[y][x] == 'P')
			{
				so_long->p_count += 1;
				so_long->chrx = x;
				so_long->chry = y;
			}
			else if (so_long->map[y][x] == 'E')
			{
				so_long->e_count += 1;
				so_long->exitx = x;
				so_long->exity = y;
			}
			else if (so_long->map[y][x] == 'C')
				so_long->c_count += 1;	
			x++;	
		}
		y++;
	}
	count_check(so_long);
}

void invalid_char(t_game *so_long, int x, int y)
{
	y = 0;

	while (y < so_long->mapy)
	{
		x = 0;
		while (x < so_long-> mapx)
		{
			if (so_long->map[y][x] != 'P' && so_long->map[y][x] != 'E' 
				&& so_long->map[y][x] != 'C' && so_long->map[y][x] != '1' 
				&& so_long->map[y][x] != '0')
			{
				ft_printf("Error: Invalid character found");
				exit(1);
			}
			x++;
		}
		y++;
	}
	get_location(so_long,x,y);
}

void wall_check(t_game *so_long,int x,int y)
{
	x = 0;
	y = 0;

	while (y < so_long->mapy)
	{
		if (so_long->map[y][0] != '1' || so_long->map[y][so_long->mapx - 1] != '1')
		{
			ft_printf("Error: There is gap in walls.");
			exit(1);
		}
			
		y++;
	}

	while (x < so_long->mapx)
	{
		if (so_long->map[0][x] != '1' || so_long->map[so_long->mapy - 1][x] != '1')
		{
			ft_printf("Error: There is gap in walls.");
			exit(1);
		}
		x++;
	}
	invalid_char(so_long,x,y);
}

void mapsize_check(t_game *so_long, int i,int x)
{
	
	i = 0;
	x = so_long->mapx;
	
	while (i < so_long->mapy)
	{
		if(x != strlen_newline(so_long->map[i]))
		{
			ft_printf("Error: Map size.");
			exit(1);
		}
		i++;
	}
	if(x > 40 || so_long->mapy > 22)
	{
		ft_printf("Error: The map is too big.");
		exit(1);
	}
	wall_check(so_long,i,x);
}