/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:15:33 by pemirand          #+#    #+#             */
/*   Updated: 2025/07/10 16:41:47 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		pxl = img->addr
			+ (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int *)pxl = color;
	}
}

int	get_color(t_game *game, int tex_x, int tex_y, int side)
{
	return (*(int *)(game->textures[side].addr
		+ (tex_y * game->textures[side].line_length
			+ tex_x * (game->textures[side].bits_per_pixel / 8))));
}

void	render_wall_column(t_game *game, int x, int line_height, int side)
{
	int	start;
	int	end;
	int	tex_x;
	int	tex_y;
	int	d;

	tex_x = (int)(game->wall_x * (double)game->textures[side].width);
	if ((side == 0 && game->ray_dir[1] > 0)
		|| (side == 1 && game->ray_dir[1] < 0))
		tex_x = game->textures[side].width - tex_x - 1;
	start = -line_height / 2 + WIN_HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = line_height / 2 + WIN_HEIGHT / 2;
	if (end >= WIN_HEIGHT)
		end = WIN_HEIGHT - 1;
	while (start < end)
	{
		d = start * 256 - WIN_HEIGHT * 128 + line_height * 128;
		tex_y = ((d * game->textures[side].height) / line_height) / 256;
		ft_put_pixel(&game->screen, x, start,
			get_color(game, tex_x, tex_y, side));
		start++;
	}
}

void	mlx_loop_and_hooks(t_game *game)
{
	mlx_loop_hook(game->mlx, &game_render, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, &x_quit_game, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &on_keypress, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, &on_keyrealease, game);
	mlx_loop(game->mlx);
}
