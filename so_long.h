/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:16:39 by akar              #+#    #+#             */
/*   Updated: 2024/06/04 14:20:55 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <fcntl.h>

typedef struct s_game
{
	char	**map;
	char	**mapcopy;
	char	*mapname;
	int		mapy;
	int		mapx;
	int		exitx;
	int		exity;
	int		chrx;
	int		chry;
	int		p_count;
	int		c_count;
	int		e_count;
	int		w_count;
	int		move_count;
	int		collected_count;
	void	*mlx;
	void	*mlx_win;
	void	*exit;
	void	*collectable;
	void	*player;
	void	*wall;
	void	*freespace;

}			t_game;

typedef struct s_location
{
	int		x;
	int		y;

}			t_location;

int			countline(char *ber);
char		**get_map(t_game *so_long);
void		mapsize_check(t_game *so_long, int i, int y);
void		flood_fill(t_game *so_long);
void		free_map(t_game *so_long, int n);
void		upload_image(t_game *so_long);
void		put_image(t_game *so_long, int x, int y);
int			ft_key(int keycode, t_game *so_long);
void		ft_close(t_game *so_long);
void		ft_up(t_game *so_long);
void		ft_left(t_game *so_long);
void		ft_right(t_game *so_long);
void		ft_down(t_game *so_long);
void		ft_close(t_game *so_long);
int			strlen_newline(char *str);
void		finish_message(t_game *solong, char c);

#endif