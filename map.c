#include "Includes/so_long.h"
#include "Includes/utils.h"

static int	ft_valid_char(char c)
{
	if (c == '0')
		return (0);
	else if (c == '1')
		return (1);
	else if (c == 'C')
		return (2);
	else if (c == 'E')
		return (3);
	else if (c == 'P')
		return (4);
	else
		return (5);
}

static void	ft_clean(t_list *map_file)
{
	t_list	*current;
	t_list	*next;

	current = map_file;
	while (current != NULL)
	{
		next = current->next;
		free(current->line);
		free(current);
		current = next;
	}
}

static void	ft_error(t_list *map_file)
{
	write(1, "Error: Parsing Map\n", 19);
	ft_clean(map_file);
	free(g_so_long);
	exit(0);
}

static int	*ft_valid_line(t_list *map_file, int y)
{
	int	x;
	int	tile;
	int	*line;

	line = (int *)malloc(g_so_long->map_width * sizeof(int));
	x = 0;
	while (x < g_so_long->map_width)
	{
		tile = ft_valid_char(map_file->line[x]);
		if ((((x == 0 || x == g_so_long->map_width - 1) && tile != 1)
				|| tile == 5) || ((y == 0 || y == g_so_long->map_height - 1)
				&& tile != 1))
		{
			free(line);
			ft_error(map_file);
		}
		else
		{
			ft_tile_count(tile);
			line[x] = tile;
		}
		x++;
	}
	return (line);
}

void	ft_parse_map(const char *file)
{
	t_list	*map_file;
	int		**map;
	int		y;

	y = 0;
	map_file = ft_load_map(1, file);
	ft_init_so_long(map_file);
	map = (int **)malloc((g_so_long->map_height + 1) * sizeof(int *));
	while (y < g_so_long->map_height)
	{
		map[y] = ft_valid_line(map_file, y);
		map_file = map_file->next;
		y++;
	}
	if (g_so_long->max_collectibles < 1 || g_so_long->starting_position < 1
		|| g_so_long->exit < 1)
		ft_error(map_file);
	ft_clean(map_file);
	g_so_long->map = map;
}
