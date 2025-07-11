/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:52:57 by pemirand          #+#    #+#             */
/*   Updated: 2025/06/30 18:16:34 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	collision(t_game *game, int x, int y)
{
	if (game->map[y][x] == '0' || game->map[y][x] == 'N' ||
		game->map[y][x] == 'S' || game->map[y][x] == 'E' ||
		game->map[y][x] == 'W')
		return (1);
	return (0);
}

void	press_forward(t_game *game)
{
	if (collision(game, floor(game->pos[0] + game->dir[0] * MOVESPEED),
			floor(game->pos[1])))
		game->pos[0] += game->dir[0] * MOVESPEED;
	if (collision(game, floor(game->pos[0]),
			floor(game->pos[1] + game->dir[1] * MOVESPEED)))
		game->pos[1] += game->dir[1] * MOVESPEED;
}

void	press_back(t_game *game)
{
	if (collision(game, floor(game->pos[0] - game->dir[0] * MOVESPEED),
			floor(game->pos[1])))
		game->pos[0] -= game->dir[0] * MOVESPEED;
	if (collision(game, floor(game->pos[0]),
			floor(game->pos[1] - game->dir[1] * MOVESPEED)))
		game->pos[1] -= game->dir[1] * MOVESPEED;
}

void	press_left(t_game *game)
{
	if (collision(game, floor(game->pos[0] - game->plane[0] * MOVESPEED),
			floor(game->pos[1])))
		game->pos[0] -= game->plane[0] * MOVESPEED;
	if (collision(game, floor(game->pos[0]),
			floor(game->pos[1] - game->plane[1] * MOVESPEED)))
		game->pos[1] -= game->plane[1] * MOVESPEED;
}

void	press_right(t_game *game)
{
	if (collision(game, floor(game->pos[0] + game->plane[0] * MOVESPEED),
			floor(game->pos[1])))
		game->pos[0] += game->plane[0] * MOVESPEED;
	if (collision(game, floor(game->pos[0]),
			floor(game->pos[1] + game->plane[1] * MOVESPEED)))
		game->pos[1] += game->plane[1] * MOVESPEED;
}
