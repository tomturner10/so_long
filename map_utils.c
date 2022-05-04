#include "Includes/so_long.h"

void	ft_tile_count(int tile)
{
	if (tile == 2)
		g_so_long->max_collectibles++;
	else if (tile == 3)
		g_so_long->exit++;
	else if (tile == 4)
		g_so_long->starting_position++;
}

static int	ft_get_width(t_list *map)
{
	int	count;

	count = 0;
	while ((map->line[count] != '\n') && (map->line[count] != '\0'))
		count++;
	return (count);
}

static int	ft_get_height(t_list *map)
{
	int	count;

	count = 0;
	if (map != NULL)
	{
		count++;
		while (map->next != NULL)
		{
			map = map->next;
			count++;
		}
	}
	return (count);
}

void	ft_init_so_long(t_list *map)
{
	g_so_long = (t_so_long *)malloc(sizeof(t_so_long));
	g_so_long->map_height = ft_get_height(map);
	g_so_long->map_width = ft_get_width(map);
	g_so_long->collectibles_held = 0;
	g_so_long->max_collectibles = 0;
	g_so_long->exit = 0;
	g_so_long->starting_position = 0;
	g_so_long->moves = 0;
}
