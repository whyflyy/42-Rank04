/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:34:58 by jcavadas          #+#    #+#             */
/*   Updated: 2025/07/10 17:35:07 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	copy_map(t_game *game)
{
	int	i;

	game->map_copy = ft_calloc(sizeof(char *), (game->map_height + 1));
	if (!game->map_copy)
		error_msg("Error allocating memory!", game);
	i = 0;
	while (game->map[i])
	{
		game->map_copy[i] = ft_strdup(game->map[i]);
		i++;
	}
}

char	**resize_map(char **old_map, int old_size, int new_size, t_game *game)
{
	char	**new_map;
	int		i;

	new_map = ft_calloc(new_size + 1, sizeof(char *));
	if (!new_map)
		error_msg("Memory allocation failed while resizing map!", game);
	i = 0;
	while (i < old_size)
	{
		new_map[i] = old_map[i];
		i++;
	}
	free(old_map);
	return (new_map);
}

static char	*skip_empty_lines(int fd, char *line)
{
	while (line && is_empty_line(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

void	end_map(t_game *game, int i, char **map)
{
	map[i] = NULL;
	game->map = map;
	game->map_height = i;
	game->map_width = get_max_width(map);
	copy_map(game);
}

void	get_map(t_game *game, int fd, char *line)
{
	int		i;
	int		capacity;
	char	**map;

	i = 0;
	capacity = 8;
	map = ft_calloc(capacity + 1, sizeof(char *));
	if (!map)
		error_msg("Error allocating memory!", game);
	line = skip_empty_lines(fd, line);
	if (!line)
	{
		free(map);
		error_msg("Missing map!", game);
	}
	while (line && !is_empty_line(line))
	{
		if (i >= capacity)
			map = resize_map(map, i, (capacity *= 2), game);
		map[i++] = line;
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	end_map(game, i, map);
}
