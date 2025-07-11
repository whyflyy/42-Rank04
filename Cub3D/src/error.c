/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemirand <pemirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:12:14 by pemirand          #+#    #+#             */
/*   Updated: 2025/06/30 18:16:14 by pemirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error_msg(char *msg, t_game *game)
{
	write(2, RED "Error\n" RESET, sizeof(RED "Error\n" RESET) - 1);
	write(2, DARK_RED, sizeof(DARK_RED) - 1);
	write(2, msg, strlen(msg));
	write(2, "\n" RESET, sizeof("\n" RESET) - 1);
	quit_game(game, 1);
}
