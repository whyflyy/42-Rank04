/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_extract_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:23:53 by jcavadas          #+#    #+#             */
/*   Updated: 2025/07/10 17:19:13 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_paths(t_game *game, int file)
{
	char	*temp;
	char	*trimmed;
	int		i;

	temp = get_next_line(file);
	while (temp && !has_all(game))
	{
		strip_trailing_whitespace(temp);
		trimmed = ft_strtrim(temp, " \t\r\n");
		free(temp);
		temp = NULL;
		i = 0;
		while (is_whitespace(trimmed[i]))
			i++;
		if (trimmed[i] == '\0')
		{
			free(trimmed);
			temp = get_next_line(file);
			continue ;
		}
		process_line(game, trimmed, i);
		free(trimmed);
		if (!has_all(game))
			temp = get_next_line(file);
	}
}

void	check_texture(char *texture, char *temp, t_game *game)
{
	int	fd;

	if (access(texture, F_OK) == 0 && access(texture, R_OK) < 0)
		error_msg("Permission denied on texture file!", game);
	fd = open(texture, O_RDONLY);
	if (fd == -1)
	{
		free(temp);
		if (!strcmp(texture, game->no_texture))
			error_msg("There is no file for the North Texture!", game);
		else if (!strcmp(texture, game->so_texture))
			error_msg("There is no file for the South Texture!", game);
		else if (!strcmp(texture, game->ea_texture))
			error_msg("There is no file for the East Texture!", game);
		else if (!strcmp(texture, game->we_texture))
			error_msg("There is no file for the West Texture!", game);
	}
	close(fd);
}

void	check_files(t_game *game, char *temp)
{
	if (!check_type(game->no_texture, ".xpm"))
	{
		free(temp);
		error_msg("The North texture is not a .xpm file!", game);
	}
	else if (!check_type(game->so_texture, ".xpm"))
	{
		free(temp);
		error_msg("The South texture is not a .xpm file!", game);
	}
	else if (!check_type(game->we_texture, ".xpm"))
	{
		free(temp);
		error_msg("The West texture is not a .xpm file!", game);
	}
	else if (!check_type(game->ea_texture, ".xpm"))
	{
		free(temp);
		error_msg("The East texture is not a .xpm file!", game);
	}
	check_texture(game->no_texture, temp, game);
	check_texture(game->so_texture, temp, game);
	check_texture(game->ea_texture, temp, game);
	check_texture(game->we_texture, temp, game);
}

static void	validate_map(t_game *game)
{
	get_player_pos(game);
	flood_fill(game->map_copy, game->pos[1], game->pos[0], game);
	free_map(game->map_copy);
	copy_map(game);
	flood_fill_check_chars(game->map_copy, game->pos[1],
		game->pos[0], game);
	if (!game->valid_map)
		error_msg("Map is not surrounded by walls!", game);
}

void	extract(t_game *game)
{
	char	*temp;

	if (access(game->filename, F_OK) == 0 && access(game->filename, R_OK) < 0)
		error_msg("Permission denied on config file!", game);
	game->file = open(game->filename, O_RDONLY);
	if (game->file < 0)
		error_msg("File not found or invalid!", game);
	get_paths(game, game->file);
	temp = get_next_line(game->file);
	if (!has_all(game))
		error_msg("Missing configuration for texture or colour!", game);
	else if (!temp)
	{
		free(temp);
		error_msg
			("Missing map or it's not the last configuration on file!", game);
	}
	check_files(game, temp);
	get_map(game, game->file, temp);
	validate_map(game);
	close(game->file);
}
