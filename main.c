/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:31:15 by akar              #+#    #+#             */
/*   Updated: 2024/06/04 14:24:00 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	name_control(char *str);
static void	reset_value(t_game *so_long);

int	main(int ac, char **av)
{
	int		x;
	int		y;
	t_game	*so_long;

	if (ac != 2 || !name_control(av[1]))
	{
		ft_printf("Error: Number or name of arguments incorrect");
		return (0);
	}
	so_long = malloc(sizeof(t_game));
	reset_value(so_long);
	so_long->mapname = av[1];
	so_long->mapy = countline(av[1]);
	so_long->map = get_map(so_long);
	mapsize_check(so_long, x, y);
	flood_fill(so_long);
	so_long->mlx = mlx_init();
	so_long->mlx_win = mlx_new_window(so_long->mlx, so_long->mapx * 64,
			so_long->mapy * 64, "so_long");
	upload_image(so_long);
	put_image(so_long, x, y);
	mlx_key_hook(so_long->mlx_win, ft_key, so_long);
	mlx_hook(so_long->mlx_win, 17, 0, ft_close, so_long);
	mlx_loop(so_long->mlx);
}

static int	name_control(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == 'r' && str[i - 1] == 'e' && str[i - 2] == 'b'
		&& str[i - 3] == '.')
		return (1);
	return (0);
}

static void	reset_value(t_game *so_long)
{
	so_long->map = NULL;
	so_long->mapcopy = NULL;
	so_long->mapname = NULL;
	so_long->mapy = 0;
	so_long->mapx = 0;
	so_long->exitx = 0;
	so_long->exity = 0;
	so_long->chrx = 0;
	so_long->chry = 0;
	so_long->p_count = 0;
	so_long->c_count = 0;
	so_long->collected_count = 0;
	so_long->e_count = 0;
	so_long->w_count = 0;
	so_long->mlx = NULL;
	so_long->mlx_win = NULL;
}
