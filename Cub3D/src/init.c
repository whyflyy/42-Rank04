/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:22:14 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/23 17:30:58 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_vars(t_game *game)
{
	game->map = NULL;
	game->map_copy = NULL;
	game->map_height = 0;
	game->valid_map = 1;
	game->no_texture = NULL;
	game->so_texture = NULL;
	game->ea_texture = NULL;
	game->we_texture = NULL;
	game->floor_clr[0] = -1;
	game->floor_clr[1] = -1;
	game->floor_clr[2] = -1;
	game->ceiling_clr[0] = -1;
	game->ceiling_clr[1] = -1;
	game->ceiling_clr[2] = -1;
	game->filename = NULL;
	game->file = -1;
	game->dir[0] = 0;
	game->dir[1] = 0;
	game->pos[0] = 0;
	game->pos[1] = 0;
	game->plane[0] = 0;
	game->plane[1] = 0;
}

void	init_ray_vars(t_game *game)
{
	game->map_pos[0] = floor(game->pos[0]);
	game->map_pos[1] = floor(game->pos[1]);
	game->side_dist[0] = 0;
	game->side_dist[1] = 0;
	game->delta_dist[0] = 0;
	game->delta_dist[1] = 0;
	game->step[0] = 0;
	game->step[1] = 0;
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window
		(game->mlx, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
	game->screen.img
		= mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->screen.addr
		= mlx_get_data_addr(game->screen.img, &game->screen.bits_per_pixel,
			&game->screen.line_length, &game->screen.endian);
	load_texture(game, &game->textures[0], game->no_texture);
	load_texture(game, &game->textures[1], game->so_texture);
	load_texture(game, &game->textures[2], game->ea_texture);
	load_texture(game, &game->textures[3], game->we_texture);
}
