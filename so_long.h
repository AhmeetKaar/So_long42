#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

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
void		wall_check(t_game *so_long, int x, int y);
void		invalid_char(t_game *so_long, int x, int y);
void		get_location(t_game *so_long, int x, int y);
void		count_check(t_game *so_long);
void		flood_fill(t_game *so_long);
void		f_fill(char **tab, t_location mapsize, int y, int x);
void		flf_check(t_game *so_long);
void		free_map(t_game *so_long, int n);
int			strlen_newline(char *str);
void		reset_value(t_game *so_long);
void		upload_image(t_game *so_long);
void		put_image(t_game *so_long, int x, int y);
int			ft_key(int keycode, t_game *so_long);
void		ft_close(t_game *so_long);
void		put_image(t_game *so_long, int x, int y);
void		upload_image(t_game *so_long);

#endif