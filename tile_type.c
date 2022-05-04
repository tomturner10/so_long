/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:31:18 by tturner           #+#    #+#             */
/*   Updated: 2022/05/04 12:31:18 by tturner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/so_long.h"
#include "mlx.h"

void	ft_collectible(t_mlx *mlx, int y, int x)
{
	if (y % 2 == 0)
	{
		if (x % 2 == 0)
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
				g_so_long->tiles->t_plant_1,
				x * TILE_SIZE, y * TILE_SIZE);
		else
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
				g_so_long->tiles->t_plant_2,
				x * TILE_SIZE, y * TILE_SIZE);
	}
	else
	{
		if (x % 2 == 0)
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
				g_so_long->tiles->t_plant_3,
				x * TILE_SIZE, y * TILE_SIZE);
		else
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
				g_so_long->tiles->t_plant_4,
				x * TILE_SIZE, y * TILE_SIZE);
	}
}

void	ft_wall_last_row(t_mlx *mlx, int y, int x)
{
	if (x == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			g_so_long->tiles->t_wall_dl,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (x == g_so_long->map_width - 1)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			g_so_long->tiles->t_wall_dr,
			x * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			g_so_long->tiles->t_wall_d,
			x * TILE_SIZE, y * TILE_SIZE);
}

void	ft_wall_first_row(t_mlx *mlx, int y, int x)
{
	if (x == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			g_so_long->tiles->t_wall_ul, x * TILE_SIZE, y * TILE_SIZE);
	else if (x == g_so_long->map_width - 1)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			g_so_long->tiles->t_wall_ur,
			x * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			g_so_long->tiles->t_wall_u,
			x * TILE_SIZE, y * TILE_SIZE);
}

void	ft_wall(t_mlx *mlx, int y, int x)
{
	if (y == 0)
		ft_wall_first_row(mlx, y, x);
	else if (y == g_so_long->map_height - 1)
		ft_wall_last_row(mlx, y, x);
	else if (x == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			g_so_long->tiles->t_wall_l,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (x == g_so_long->map_width - 1)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			g_so_long->tiles->t_wall_r,
			x * TILE_SIZE, y * TILE_SIZE);
	else
	{
		if (x % 2 == 0)
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
				g_so_long->tiles->t_wall_m1,
				x * TILE_SIZE, y * TILE_SIZE);
		else
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
				g_so_long->tiles->t_wall_m2,
				x * TILE_SIZE, y * TILE_SIZE);
	}
}
