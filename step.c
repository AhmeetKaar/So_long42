/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akar <akar@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:57:38 by akar              #+#    #+#             */
/*   Updated: 2024/06/07 15:28:05 by akar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up(t_game *so_long)
{
	char	next_step;

	next_step = so_long->map[so_long->chry - 1][so_long->chrx];
	if (next_step == '1')
		return ;
	so_long->move_count++;
	ft_printf("Step count: %d\n", so_long->move_count);
	if (next_step == 'C')
		so_long->collected_count++;
	else if (next_step == 'E' && so_long->collected_count == so_long->c_count)
		finish_message(so_long, 'w');
	so_long->map[so_long->chry][so_long->chrx] = '0';
	so_long->chry--;
	so_long->map[so_long->chry][so_long->chrx] = 'P';
	if (so_long->map[so_long->exity][so_long->exitx] != 'E')
		so_long->map[so_long->exity][so_long->exitx] = 'E';
}

void	ft_left(t_game *so_long)
{
	char	next_step;

	next_step = so_long->map[so_long->chry][so_long->chrx - 1];
	if (next_step == '1')
		return ;
	so_long->move_count++;
	ft_printf("Step count: %d\n", so_long->move_count);
	if (next_step == 'C')
		so_long->collected_count++;
	else if (next_step == 'E' && so_long->c_count == so_long->collected_count)
		finish_message(so_long, 'w');
	so_long->map[so_long->chry][so_long->chrx] = '0';
	so_long->chrx--;
	so_long->map[so_long->chry][so_long->chrx] = 'P';
	if (so_long->map[so_long->exity][so_long->exitx] != 'E')
		so_long->map[so_long->exity][so_long->exitx] = 'E';
}

void	ft_right(t_game *so_long)
{
	char	next_step;

	next_step = so_long->map[so_long->chry][so_long->chrx + 1];
	if (next_step == '1')
		return ;
	so_long->move_count++;
	ft_printf("Step count: %d\n", so_long->move_count);
	if (next_step == 'C')
		so_long->collected_count++;
	else if (next_step == 'E' && so_long->c_count == so_long->collected_count)
		finish_message(so_long, 'w');
	so_long->map[so_long->chry][so_long->chrx] = '0';
	so_long->chrx++;
	so_long->map[so_long->chry][so_long->chrx] = 'P';
	if (so_long->map[so_long->exity][so_long->exitx] != 'E')
		so_long->map[so_long->exity][so_long->exitx] = 'E';
}

void	ft_down(t_game *so_long)
{
	char	next_step;

	next_step = so_long->map[so_long->chry + 1][so_long->chrx];
	if (next_step == '1')
		return ;
	so_long->move_count++;
	ft_printf("Step count: %d\n", so_long->move_count);
	if (next_step == 'C')
		so_long->collected_count++;
	else if (next_step == 'E' && so_long->collected_count == so_long->c_count)
		finish_message(so_long, 'w');
	so_long->map[so_long->chry][so_long->chrx] = '0';
	so_long->chry++;
	so_long->map[so_long->chry][so_long->chrx] = 'P';
	if (so_long->map[so_long->exity][so_long->exitx] != 'E')
		so_long->map[so_long->exity][so_long->exitx] = 'E';
}

int	ft_close(t_game *so_long)
{
	ft_printf("Game closed.");
	free_map(so_long, 1);
	exit(1);
}
