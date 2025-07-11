/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:06:13 by pemirand          #+#    #+#             */
/*   Updated: 2025/07/10 16:09:29 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	delta_dist_calc(t_game *game, double ray_dir_x, double ray_dir_y)
{
	if (ray_dir_x == 0)
		game->delta_dist[0] = 1e30;
	else
		game->delta_dist[0] = fabs(1 / ray_dir_x);
	if (ray_dir_y == 0)
		game->delta_dist[1] = 1e30;
	else
		game->delta_dist[1] = fabs(1 / ray_dir_y);
}

void	side_dist_calc(t_game *game, double ray_dir_x, double ray_dir_y)
{
	if (ray_dir_x < 0)
	{
		game->step[0] = -1;
		game->side_dist[0]
			= (game->pos[0] - game->map_pos[0]) * game->delta_dist[0];
	}
	else
	{
		game->step[0] = 1;
		game->side_dist[0]
			= (game->map_pos[0] + 1.0 - game->pos[0]) * game->delta_dist[0];
	}
	if (ray_dir_y < 0)
	{
		game->step[1] = -1;
		game->side_dist[1]
			= (game->pos[1] - game->map_pos[1]) * game->delta_dist[1];
	}
	else
	{
		game->step[1] = 1;
		game->side_dist[1]
			= (game->map_pos[1] + 1.0 - game->pos[1]) * game->delta_dist[1];
	}
}

double	dda_aux(t_game *game, double ray_dir_x, double ray_dir_y, int side)
{
	double	perp_dist;

	if (side == 0)
	{
		perp_dist = (game->side_dist[0] - game->delta_dist[0]);
		if (ray_dir_x < 0)
			game->hit_side = 'E';
		else
			game->hit_side = 'O';
	}
	else
	{
		perp_dist = (game->side_dist[1] - game->delta_dist[1]);
		if (ray_dir_y < 0)
			game->hit_side = 'S';
		else
			game->hit_side = 'N';
	}
	if (side == 0)
		game->wall_x = game->pos[1] + perp_dist * game->ray_dir[1];
	else
		game->wall_x = game->pos[0] + perp_dist * game->ray_dir[0];
	game->wall_x -= floor(game->wall_x);
	return (perp_dist);
}

double	dda(t_game *game, double ray_dir_x, double ray_dir_y)
{
	double	perp_dist;
	int		side;

	while (1)
	{
		if (game->side_dist[0] < game->side_dist[1])
		{
			game->side_dist[0] += game->delta_dist[0];
			game->map_pos[0] += game->step[0];
			side = 0;
		}
		else
		{
			game->side_dist[1] += game->delta_dist[1];
			game->map_pos[1] += game->step[1];
			side = 1;
		}
		if (game->map[game->map_pos[1]][game->map_pos[0]] == '1')
			break ;
	}
	perp_dist = dda_aux(game, ray_dir_x, ray_dir_y, side);
	if (perp_dist < 0.01)
		perp_dist = 0.01;
	return (perp_dist);
}

void	render_vertical_line(t_game *game, int x, double perp_dist)
{
	int	line_height;
	int	start;
	int	end;

	line_height = (int)(WIN_HEIGHT / perp_dist);
	start = -line_height / 2 + WIN_HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = line_height / 2 + WIN_HEIGHT / 2;
	if (end >= WIN_HEIGHT)
		end = WIN_HEIGHT - 1;
	if (game->hit_side == 'N')
		render_wall_column(game, x, line_height, 0);
	else if (game->hit_side == 'S')
		render_wall_column(game, x, line_height, 1);
	else if (game->hit_side == 'E')
		render_wall_column(game, x, line_height, 2);
	else if (game->hit_side == 'O')
		render_wall_column(game, x, line_height, 3);
}
