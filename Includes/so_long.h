#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

#define TILE_SIZE 64

typedef struct s_mlx {
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_tiles {
	void *t_player;
	void *t_wall_u;
	void *t_wall_ul;
	void *t_wall_ur;
	void *t_wall_d;
	void *t_wall_dl;
	void *t_wall_dr;
	void *t_wall_l;
	void *t_wall_r;
	void *t_wall_m1;
	void *t_wall_m2;
	void *t_door;
	void *t_plant_1;
	void *t_plant_2;
	void *t_plant_3;
	void *t_plant_4;
	void *black;
}				t_tiles;

typedef struct s_list{
	char *line;
	int y;
	struct s_list *next;
}				t_list;

typedef struct s_so_long{
	int map_width;
	int map_height;
	int **map;
	t_tiles *tiles;
	int collectibles_held;
	int max_collectibles;
	int exit;
	int starting_position;
	int moves;
}				t_so_long;

t_so_long	*g_so_long;

void	ft_parse_map(const char *file);
void	ft_init_so_long(t_list *map);
t_list	*ft_load_map(int fd, const char *file);
t_tiles	*ft_init_tiles(void *mlx);
void	ft_choose_tile(t_mlx *mlx, int y, int x);
int		ft_movable_tile(int y, int x, t_mlx *mlx);
void	ft_tile_count(int tile);
void	ft_wall(t_mlx *mlx, int y, int x);
void	ft_collectible(t_mlx *mlx, int y, int x);
void	ft_exit(t_mlx *mlx);

#endif
