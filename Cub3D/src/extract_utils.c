/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:04:07 by jcavadas          #+#    #+#             */
/*   Updated: 2025/07/10 17:49:37 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	colour_is_set(int colour[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (colour[i] < 0)
			return (0);
		i++;
	}
	return (1);
}

void	process_line(t_game *game, char *temp, int i)
{
	if ((!ft_strncmp(temp + i, "NO", 2) && is_whitespace(temp[i + 2]))
		|| (!ft_strncmp(temp + i, "N", 1) && is_whitespace(temp[i + 1])))
		game->no_texture = get_texture(temp, game);
	else if ((!ft_strncmp(temp + i, "SO", 2) && is_whitespace(temp[i + 2]))
		|| (!ft_strncmp(temp + i, "S", 1) && is_whitespace(temp[i + 1])))
		game->so_texture = get_texture(temp, game);
	else if ((!ft_strncmp(temp + i, "WE", 2) && is_whitespace(temp[i + 2]))
		|| (!ft_strncmp(temp + i, "W", 1) && is_whitespace(temp[i + 1])))
		game->we_texture = get_texture(temp, game);
	else if ((!ft_strncmp(temp + i, "EA", 2) && is_whitespace(temp[i + 2]))
		|| (!ft_strncmp(temp + i, "E", 1) && is_whitespace(temp[i + 1])))
		game->ea_texture = get_texture(temp, game);
	else if (temp[i] == 'F' && is_whitespace(temp[i + 1]))
		get_colour(temp, game->floor_clr, game);
	else if (temp[i] == 'C' && is_whitespace(temp[i + 1]))
		get_colour(temp, game->ceiling_clr, game);
	else if (temp[i] == '1' || temp[i] == '0')
		return ;
	else
	{
		free(temp);
		error_msg("Invalid configuration identifier!", game);
	}
}

char	*get_texture(char *line, t_game *game)
{
	char	*path;
	char	*temp;
	int		i;
	int		end;

	i = 0;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == ' ')
		i++;
	if (line[i] >= 'A' && line[i] <= 'Z')
		i++;
	if (line[i] >= 'A' && line[i] <= 'Z')
		i++;
	while ((line[i] >= 9 && line[i] <= 13) || line[i] == ' ')
		i++;
	end = i;
	while (line[end] && line[end] != '\n')
		end++;
	temp = ft_substr(line, i, end - i);
	if (!temp)
		error_msg("Error allocating for texture path", game);
	path = ft_strtrim(temp, " \t\n");
	free(temp);
	return (path);
}

void	free_split(char **split, char *line, char *msg, t_game *game)
{
	int	i;

	if (line)
		free(line);
	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	if (msg)
		error_msg(msg, game);
}

void	get_colour(char *line, int *dest, t_game *game)
{
	char	**rgb_split;
	int		i;

	i = 0;
	while (line[i] && (line[i] == 'F' || line[i] == 'C' || line[i] == ' '))
		i++;
	rgb_split = ft_split(line + i, ',');
	if (!rgb_split)
		error_msg("Error allocating memory!", game);
	i = 0;
	while (i < 3)
	{
		if (!rgb_split[i])
			free_split(rgb_split, line, "Invalid colour format!", game);
		dest[i] = ft_atoi(rgb_split[i]);
		if (dest[i] < 0 || dest[i] > 255)
			free_split(rgb_split,
				line, "Colour values must be between 0 and 255!", game);
		i++;
	}
	free_split(rgb_split, NULL, NULL, NULL);
}
