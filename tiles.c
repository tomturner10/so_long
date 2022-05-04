#include "Includes/so_long.h"
#include "mlx.h"

void	ft_init_tiles_cont(void *mlx, int t, t_tiles *tiles)
{
	tiles->t_wall_m1 = mlx_xpm_file_to_image(mlx, "a/wall_m1.xpm", &t, &t);
	tiles->t_wall_m2 = mlx_xpm_file_to_image(mlx, "a/wall_m2.xpm", &t, &t);
	tiles->t_door = mlx_xpm_file_to_image(mlx, "a/door.xpm", &t, &t);
	tiles->t_plant_1 = mlx_xpm_file_to_image(mlx, "a/plant_01.xpm", &t, &t);
	tiles->t_plant_2 = mlx_xpm_file_to_image(mlx, "a/plant_02.xpm", &t, &t);
	tiles->t_plant_3 = mlx_xpm_file_to_image(mlx, "a/plant_03.xpm", &t, &t);
	tiles->t_plant_4 = mlx_xpm_file_to_image(mlx, "a/plant_04.xpm", &t, &t);
	tiles->black = mlx_xpm_file_to_image(mlx, "a/black.xpm", &t, &t);
}

t_tiles	*ft_init_tiles(void *mlx)
{
	int		t;
	t_tiles	*tiles;

	tiles = (t_tiles *)malloc(sizeof(t_tiles));
	t = TILE_SIZE;
	tiles->t_player = mlx_xpm_file_to_image(mlx, "a/player.xpm", &t, &t);
	tiles->t_wall_u = mlx_xpm_file_to_image(mlx, "a/wall_u.xpm", &t, &t);
	tiles->t_wall_ul = mlx_xpm_file_to_image(mlx, "a/wall_ul.xpm", &t, &t);
	tiles->t_wall_ur = mlx_xpm_file_to_image(mlx, "a/wall_ur.xpm", &t, &t);
	tiles->t_wall_d = mlx_xpm_file_to_image(mlx, "a/wall_d.xpm", &t, &t);
	tiles->t_wall_dl = mlx_xpm_file_to_image(mlx, "a/wall_dl.xpm", &t, &t);
	tiles->t_wall_dr = mlx_xpm_file_to_image(mlx, "a/wall_dr.xpm", &t, &t);
	tiles->t_wall_r = mlx_xpm_file_to_image(mlx, "a/wall_r.xpm", &t, &t);
	tiles->t_wall_l = mlx_xpm_file_to_image(mlx, "a/wall_l.xpm", &t, &t);
	ft_init_tiles_cont(mlx, t, tiles);
	return (tiles);
}

void	ft_choose_tile(t_mlx *mlx, int y, int x)
{
	if (g_so_long->map[y][x] == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			g_so_long->tiles->black, x * TILE_SIZE, y * TILE_SIZE);
	else if (g_so_long->map[y][x] == 1)
		ft_wall(mlx, y, x);
	else if (g_so_long->map[y][x] == 2)
		ft_collectible(mlx, y, x);
	else if (g_so_long->map[y][x] == 3)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			g_so_long->tiles->t_door, x * TILE_SIZE, y * TILE_SIZE);
	else if (g_so_long->map[y][x] == 4)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			g_so_long->tiles->t_player, x * TILE_SIZE, y * TILE_SIZE);
}

int	ft_movable_tile(int y, int x, t_mlx *mlx)
{
	if (g_so_long->map[y][x] != 1)
	{
		if (g_so_long->map[y][x] == 0)
			g_so_long->map[y][x] = 4;
		else if (g_so_long->map[y][x] == 2)
		{
			g_so_long->map[y][x] = 4;
			g_so_long->collectibles_held++;
		}
		else if (g_so_long->map[y][x] == 3)
		{
			if (g_so_long->collectibles_held == g_so_long->max_collectibles)
				ft_exit(mlx);
			else
				return (0);
		}
		return (1);
	}
	return (0);
}
