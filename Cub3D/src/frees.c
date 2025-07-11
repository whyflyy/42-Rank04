/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:38:49 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/30 17:13:00 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//TODO: Ir adicionando merdas que for alocando 
void	free_all(t_game *game);
void	free_textures_and_mlx(t_game *game);

void	quit_game(t_game *game, int exit_code)
{
	get_next_line(-1);
	free_all(game);
	exit(exit_code);
}

int	x_quit_game(t_game *game)
{
	quit_game(game, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	free_all(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		free_map(game->map);
	if (game->map_copy)
		free_map(game->map_copy);
	free_textures_and_mlx(game);
	if (game->file != -1)
		close(game->file);
	free(game);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_textures_and_mlx(t_game *game)
{
	int	i;

	if (game->no_texture)
		free(game->no_texture);
	if (game->so_texture)
		free(game->so_texture);
	if (game->we_texture)
		free(game->we_texture);
	if (game->ea_texture)
		free(game->ea_texture);
	i = 0;
	while (i < 4)
	{
		if (game->textures[i].img)
			mlx_destroy_image(game->mlx, game->textures[i].img);
		i++;
	}
	if (game->screen.img)
		mlx_destroy_image(game->mlx, game->screen.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
}
