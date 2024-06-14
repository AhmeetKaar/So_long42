/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:13:11 by akar              #+#    #+#             */
/*   Updated: 2024/06/01 19:37:36 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


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