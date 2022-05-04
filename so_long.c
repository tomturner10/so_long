/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:31:18 by tturner           #+#    #+#             */
/*   Updated: 2022/05/04 12:31:18 by tturner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/so_long.h"
#include "Includes/utils.h"
#include "mlx.h"

void	ft_update(t_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	while (y < g_so_long->map_height)
	{
		x = 0;
		while (x < g_so_long->map_width)
		{
			ft_choose_tile(mlx, y, x);
			x++;
		}
		y++;
	}
}

void	ft_exit(t_mlx *mlx)
{
	int	i;

	i = 0;
	free(mlx->mlx_win);
	free(mlx->mlx);
	free(mlx);
	while (i < g_so_long->map_height)
	{
		free(g_so_long->map[i]);
		i++;
	}
	free(g_so_long->map);
	free(g_so_long->tiles);
	free(g_so_long);
	exit(-1);
}

void	ft_move_player(int key, t_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	while (y < g_so_long->map_height)
	{
		x = 0;
		while (x < g_so_long->map_width)
		{
			if ((g_so_long->map[y][x] == 4)
				&& ((key == 0 && ft_movable_tile(y + 1, x, mlx))
					|| (key == 1 && ft_movable_tile(y - 1, x, mlx))
					|| (key == 2 && ft_movable_tile(y, x + 1, mlx))
					|| (key == 3 && ft_movable_tile(y, x - 1, mlx))))
			{
				write(1, ft_itoa(++g_so_long->moves),
					ft_countnbr(g_so_long->moves));
				write(1, "\n", 1);
				g_so_long->map[y][x] = 0;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	key_hook(int key, t_mlx *mlx)
{
	if (key == 53 || key == 17)
		ft_exit(mlx);
	else if (key == 1)
		ft_move_player(0, mlx);
	else if (key == 13)
		ft_move_player(1, mlx);
	else if (key == 2)
		ft_move_player(2, mlx);
	else if (key == 0)
		ft_move_player(3, mlx);
	else
		return (0);
	ft_update(mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	t_mlx		*mlx;
	t_img		img;

	if (argc < 2)
	{
		write(1, "Error: Invalid arguments", 24);
		exit(-1);
	}
	ft_parse_map(argv[1]);
	mlx = malloc(sizeof(mlx));
	mlx->mlx_win = malloc(sizeof(void *));
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, g_so_long->map_width * TILE_SIZE,
			g_so_long->map_height * TILE_SIZE, "test");
	img.img = mlx_new_image(mlx->mlx, g_so_long->map_width * TILE_SIZE,
			g_so_long->map_height * TILE_SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.img, 0, 0);
	g_so_long->tiles = ft_init_tiles(mlx->mlx);
	ft_update(mlx);
	mlx_hook(mlx->mlx_win, 17, 0, (int (*)()) ft_exit, mlx);
	mlx_key_hook(mlx->mlx_win, key_hook, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
