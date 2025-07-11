/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:12:05 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/23 15:43:10 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_more_pos(t_game *game, int *p_count, int y, int x)
{
	if (game->map[y][x] == 'W')
	{
		game->pos[0] = (float)x + 0.5f;
		game->pos[1] = (float)y + 0.5f;
		game->dir[0] = -1;
		game->dir[1] = 0;
		game->plane[1] = -0.66;
		(*p_count)++;
	}
	if (game->map[y][x] == 'E')
	{
		game->pos[0] = (float)x + 0.5f;
		game->pos[1] = (float)y + 0.5f;
		game->dir[0] = 1;
		game->dir[1] = 0;
		game->plane[1] = 0.66;
		(*p_count)++;
	}
}

void	check_pos(t_game *game, int *p_count, int y, int x)
{
	if (game->map[y][x] == 'N')
	{
		game->pos[0] = (float)x + 0.5f;
		game->pos[1] = (float)y + 0.5f;
		game->dir[0] = 0;
		game->dir[1] = -1;
		game->plane[0] = 0.66;
		(*p_count)++;
	}
	if (game->map[y][x] == 'S')
	{
		game->pos[0] = (float)x + 0.5f;
		game->pos[1] = (float)y + 0.5f;
		game->dir[0] = 0;
		game->dir[1] = 1;
		game->plane[0] = -0.66;
		(*p_count)++;
	}
	check_more_pos(game, p_count, y, x);
}

void	get_player_pos(t_game *game)
{
	int	x;
	int	y;
	int	p_count;

	y = 0;
	p_count = 0;
	while (game->map_height > y)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			check_pos(game, &p_count, y, x);
			x++;
		}
		y++;
	}
	if (p_count == 0)
		error_msg ("No player starting position!", game);
	else if (p_count > 1)
		error_msg("There can only be 1 player starting position!", game);
}

void	flood_fill(char **map_copy, int y, int x, t_game *game)
{
	if (y < 0 || x < 0 || y >= game->map_height
		|| x >= (int)ft_strlen(game->map[y]))
	{
		game->valid_map = 0;
		return ;
	}
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'F')
		return ;
	if (map_copy[y][x] == ' ')
		game->map[y][x] = '0';
	map_copy[y][x] = 'F';
	flood_fill(map_copy, y, x - 1, game);
	flood_fill(map_copy, y, x + 1, game);
	flood_fill(map_copy, y - 1, x, game);
	flood_fill(map_copy, y + 1, x, game);
}

void	flood_fill_check_chars(char **map_copy, int y, int x, t_game *game)
{
	if (y < 0 || x < 0 || y >= game->map_height
		|| x >= (int)ft_strlen(map_copy[y]))
		return ;
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'F')
		return ;
	if (map_copy[y][x] != ' ' && map_copy[y][x] != '0'
		&& map_copy[y][x] != 'N' && map_copy[y][x] != 'S'
		&& map_copy[y][x] != 'W' && map_copy[y][x] != 'E'
		&& map_copy[y][x] != '\n')
		error_msg("Invalid character in the map!", game);
	map_copy[y][x] = 'F';
	flood_fill_check_chars(map_copy, y, x - 1, game);
	flood_fill_check_chars(map_copy, y, x + 1, game);
	flood_fill_check_chars(map_copy, y - 1, x, game);
	flood_fill_check_chars(map_copy, y + 1, x, game);
}
