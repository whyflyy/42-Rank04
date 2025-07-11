/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:35:34 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/30 11:35:41 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_type(char *filename, char *extension)
{
	size_t	len;
	size_t	ext_len;
	size_t	i;
	size_t	j;

	i = 0;
	len = ft_strlen(filename);
	ext_len = ft_strlen(extension);
	j = ext_len;
	while (i++ <= ext_len)
	{
		if (filename[len--] != extension[j--])
			return (false);
	}
	return (true);
}

int	initial_checks(int argc, char **argv)
{
	if (argc != 2)
	{
		printf(RED"Error\nIncorrect usage!\n"RESET);
		printf(DARK_RED"Program must be run with: ./cub3d <file>.cub\n"RESET);
		exit(1);
	}
	if (!(check_type(argv[1], ".cub")))
	{
		error_msg("Wrong file type! must be a .cub file!", NULL);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	initial_checks(argc, argv);
	game = ft_calloc(1, sizeof(t_game));
	init_vars(game);
	game->filename = argv[1];
	extract(game);
	init_mlx(game);
	mlx_loop_and_hooks(game);
	quit_game(game, 0);
	return (0);
}
