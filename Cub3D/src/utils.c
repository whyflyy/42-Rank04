/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:35:04 by jcavadas          #+#    #+#             */
/*   Updated: 2025/07/10 17:31:35 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n' && (line[i] < 9 || line[i] > 13))
			return (0);
		i++;
	}
	return (1);
}

int	is_whitespace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

void	strip_trailing_whitespace(char *s)
{
	int	len;

	len = ft_strlen(s);
	while (len > 0 && is_whitespace(s[len - 1]))
	{
		s[len - 1] = '\0';
		len--;
	}
}

int	get_max_width(char **map)
{
	int	i;
	int	j;
	int	max_width;

	i = 0;
	max_width = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > max_width)
			max_width = j - 1;
		i++;
	}
	return (max_width);
}

int	has_all(t_game *game)
{
	if (!game->no_texture)
		return (0);
	else if (!game->so_texture)
		return (0);
	else if (!game->we_texture)
		return (0);
	else if (!game->ea_texture)
		return (0);
	else if (!colour_is_set(game->floor_clr))
		return (0);
	else if (!colour_is_set(game->ceiling_clr))
		return (0);
	return (1);
}
