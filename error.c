/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:13:11 by akar              #+#    #+#             */
/*   Updated: 2024/05/28 19:13:34 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errormessage(t_game *solong, char c)
{
	if (c == 'f')
	{
		free_map(solong, 1);
		free_map(solong, 2);
		ft_printf("Flood fill error");
	}
	else if (c == 'm')
	{
		free_map(solong, 1);
		ft_printf("Map size error");
	}
	else if (c == 'g')
	{
		free_map(solong, 1);
		ft_printf("There's a gap on the wall.");
	}
	else
	{
		errormessage2(solong, c);
	}
	free(solong);
	mlx_destroy_window(solong->mlx, solong->mlx_win);
	exit(1);
}

void	errormessage2(t_game *solong, char c)
{
	if (c == 'c')
	{
		free_map(solong, 1);
		ft_printf("There's a component that shouldn't exist in map");
	}
	else if (c == 'a')
	{
		free_map(solong, 1);
		ft_printf("Invalid component amount");
	}
	else if (c == 'w')
	{
		free_map(solong, 1);
		ft_printf("Congratulations, you won. Kacchoww!");
	}
	free(solong);
	mlx_destroy_window(solong->mlx, solong->mlx_win);
	exit(1);
}