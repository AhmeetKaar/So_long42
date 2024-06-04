/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:02:12 by akar              #+#    #+#             */
/*   Updated: 2024/06/04 14:24:31 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_imag(t_game *so_long, int x, int y);

int	ft_key(int keycode, t_game *so_long)
{
	int	x;
	int	y;

	if (keycode == 13 || keycode == 126)
		ft_up(so_long);
	else if (keycode == 0 || keycode == 123)
		ft_left(so_long);
	else if (keycode == 2 || keycode == 124)
		ft_right(so_long);
	else if (keycode == 1 || keycode == 125)
		ft_down(so_long);
	else if (keycode == 53)
		ft_close(so_long);
	y = 0;
	put_image(so_long, x, y);
}

void	upload_image(t_game *so_long)
{
	int	x;
	int	y;

	so_long->wall = mlx_xpm_file_to_image(so_long->mlx, "textures/rock1.xpm",
			&x, &y);
	so_long->freespace = mlx_xpm_file_to_image(so_long->mlx,
			"textures/road.xpm", &x, &y);
	so_long->player = mlx_xpm_file_to_image(so_long->mlx,
			"textures/lightningmq.xpm", &x, &y);
	so_long->collectable = mlx_xpm_file_to_image(so_long->mlx,
			"textures/collectable.xpm", &x, &y);
	so_long->exit = mlx_xpm_file_to_image(so_long->mlx, "textures/exit.xpm", &x,
			&y);
	if (!so_long->wall && !so_long->freespace && !so_long->player
		&& !so_long->collectable && !so_long->exit)
	{
		ft_printf("Error: Missing image.");
		exit(1);
	}
}

void	put_image(t_game *so_long, int x, int y)
{
	y = 0;
	while (so_long->map[y])
	{
		x = 0;
		while (so_long->map[y][x])
		{
			put_imag(so_long, x, y);
			x++;
		}
		y++;
	}
}

static void	put_imag(t_game *so_long, int x, int y)
{
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->freespace,
		x * 64, y * 64);
	if (so_long->map[y][x] == '1')
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->wall, x
			* 64, y * 64);
	else if (so_long->map[y][x] == 'E')
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->exit, x
			* 64, y * 64);
	else if (so_long->map[y][x] == 'C')
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
			so_long->collectable, x * 64, y * 64);
	else if (so_long->map[y][x] == 'P')
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->player,
			x * 64, y * 64);
	if (so_long->map[y][x] == 'E' && so_long->chrx == so_long->exitx
		&& so_long->exity == so_long->chry)
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->player,
			x * 64, y * 64);
}

void	finish_message(t_game *solong, char c)
{
	if (c == 'w')
	{
		free_map(solong, 1);
		ft_printf("Congratulations, you won.");
	}
	free(solong);
	mlx_destroy_window(solong->mlx, solong->mlx_win);
	exit(1);
}
