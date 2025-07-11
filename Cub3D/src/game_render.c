/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:32:55 by pemirand          #+#    #+#             */
/*   Updated: 2025/06/30 17:13:24 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	rgb_to_int(int rgb[3])
{
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void	floor_render(t_game *game)
{
	int	x;
	int	y;
	int	floor_colour;

	floor_colour = rgb_to_int(game->floor_clr);
	x = 0;
	while (x < WIN_WIDTH)
	{
		y = WIN_HEIGHT / 2;
		while (y < WIN_HEIGHT)
		{
			ft_put_pixel(&game->screen, x, y, floor_colour);
			y++;
		}
		x++;
	}
}

void	sky_render(t_game *game)
{
	int	x;
	int	y;
	int	ceiling_colour;

	ceiling_colour = rgb_to_int(game->ceiling_clr);
	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT / 2)
		{
			ft_put_pixel(&game->screen, x, y, ceiling_colour);
			y++;
		}
		x++;
	}
}

void	camera_render(t_game *game)
{
	int		x;
	double	camera_x;

	x = 0;
	while (x <= WIN_WIDTH)
	{
		init_ray_vars(game);
		camera_x = 2 * x / (double) WIN_WIDTH - 1;
		game->ray_dir[0] = game->dir[0] + game->plane[0] * camera_x;
		game->ray_dir[1] = game->dir[1] + game->plane[1] * camera_x;
		delta_dist_calc(game, game->ray_dir[0], game->ray_dir[1]);
		side_dist_calc(game, game->ray_dir[0], game->ray_dir[1]);
		render_vertical_line(game, x, dda(game, game->ray_dir[0],
				game->ray_dir[1]));
		x++;
	}
}

int	game_render(t_game *game)
{
	sky_render(game);
	floor_render(game);
	update_moves(game);
	camera_render(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
	return (0);
}
