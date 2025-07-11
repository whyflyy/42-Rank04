/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:52:57 by pemirand          #+#    #+#             */
/*   Updated: 2025/06/30 18:14:58 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_right(t_game *game)
{
	double	old;

	old = game->dir[0];
	game->dir[0] = game->dir[0] * cos(ROTATESPEED)
		- game->dir[1] * sin(ROTATESPEED);
	game->dir[1] = old * sin(ROTATESPEED) + game->dir[1] * cos(ROTATESPEED);
	old = game->plane[0];
	game->plane[0] = game->plane[0] * cos(ROTATESPEED)
		- game->plane[1] * sin(ROTATESPEED);
	game->plane[1] = old * sin(ROTATESPEED) + game->plane[1] * cos(ROTATESPEED);
}

void	rotate_left(t_game *game)
{
	double	old;

	old = game->dir[0];
	game->dir[0] = game->dir[0] * cos(-ROTATESPEED)
		- game->dir[1] * sin(-ROTATESPEED);
	game->dir[1] = old * sin(-ROTATESPEED) + game->dir[1] * cos(-ROTATESPEED);
	old = game->plane[0];
	game->plane[0] = game->plane[0] * cos(-ROTATESPEED)
		- game->plane[1] * sin(-ROTATESPEED);
	game->plane[1] = old * sin(-ROTATESPEED)
		+ game->plane[1] * cos(-ROTATESPEED);
}

int	on_keypress(int keysym, t_game *game)
{
	if (keysym == ESC_KEY)
		quit_game(game, 0);
	else if (keysym == W_KEY)
		game->mov.forward = 1;
	else if (keysym == S_KEY)
		game->mov.back = 1;
	else if (keysym == A_KEY)
		game->mov.left = 1;
	else if (keysym == D_KEY)
		game->mov.right = 1;
	else if (keysym == RIGHT_KEY)
		game->mov.rotate_right = 1;
	else if (keysym == LEFT_KEY)
		game->mov.rotate_left = 1;
	return (0);
}

int	on_keyrealease(int keysym, t_game *game)
{
	if (keysym == ESC_KEY)
		quit_game(game, 0);
	else if (keysym == W_KEY)
		game->mov.forward = 0;
	else if (keysym == S_KEY)
		game->mov.back = 0;
	else if (keysym == A_KEY)
		game->mov.left = 0;
	else if (keysym == D_KEY)
		game->mov.right = 0;
	else if (keysym == RIGHT_KEY)
		game->mov.rotate_right = 0;
	else if (keysym == LEFT_KEY)
		game->mov.rotate_left = 0;
	return (0);
}

int	update_moves(t_game *game)
{
	if (game->mov.forward == 1)
		press_forward(game);
	if (game->mov.back == 1)
		press_back(game);
	if (game->mov.left == 1)
		press_left(game);
	if (game->mov.right == 1)
		press_right(game);
	if (game->mov.rotate_left == 1)
		rotate_left(game);
	if (game->mov.rotate_right == 1)
		rotate_right(game);
	return (0);
}
