/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:02:12 by akar              #+#    #+#             */
/*   Updated: 2024/05/25 19:14:28 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	ft_key(int keycode, t_game *so_long)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (keycode == 13)
		ft_up(so_long);
	else if (keycode == 0)
		ft_left(so_long);
	else if (keycode == 2)
		ft_right(so_long);
	else if (keycode == 1)
		ft_down(so_long);
	else if (keycode == 53)
		ft_close(so_long);
	put_image(so_long, x, y);
}


void	upload_image(t_game *so_long)
{
	int	x;
	int	y;

	so_long->exit = mlx_xpm_file_to_image(so_long->mlx, "textures/exit.xpm", &x,
			&y);
	so_long->player = mlx_xpm_file_to_image(so_long->mlx, "img/lightningmq.xpm",
			&x, &y);
	so_long->collectable = mlx_xpm_file_to_image(so_long->mlx,
			"img/collectable.xpm", &x, &y);
	so_long->wall = mlx_xpm_file_to_image(so_long->mlx, "img/rock1.xpm", &x,
			&y);
	so_long->freespace = mlx_xpm_file_to_image(so_long->mlx, "img/road.xpm", &x,
			&y);
	if (!so_long->exit || !so_long->player || !so_long->collectable
		|| !so_long->wall || !so_long->freespace)
	{
		ft_printf("Missing image");
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
			if (so_long->map[y][x] == '1')
				mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
					so_long->wall, x * 64, y * 64);
			else if (so_long->map[y][x] == '0')
				mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
					so_long->freespace, x * 64, y * 64);
			else if (so_long->map[y][x] == 'P')
				mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
					so_long->player, x * 64, y * 64);
			else if (so_long->map[y][x] == 'E')
				mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
					so_long->exit, x * 64, y * 64);
			else if (so_long->map[y][x] == 'C')
				mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
					so_long->collectable, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
