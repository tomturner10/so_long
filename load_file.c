#include "Includes/so_long.h"
#include "Includes/utils.h"

static t_list	*ft_get_list(t_list *list, t_list *curr, t_list *new)
{
	if (!list)
		list = new;
	else
	{
		curr = list;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
	return (list);
}

int	ft_get_file(int fd, const char *file)
{
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error: Invalid file", 19);
		exit(-1);
	}
	return (fd);
}

t_list	*ft_load_map(int fd, const char *file)
{
	t_list	*list;
	t_list	*curr;
	t_list	*new;
	char	*line;
	int		count;

	list = NULL;
	curr = NULL;
	new = NULL;
	count = 1;
	fd = ft_get_file(fd, file);
	while (1)
	{
		line = get_next_line(fd, 1000);
		if (!line)
			break ;
		new = malloc(sizeof(t_list));
		new->next = NULL;
		new->line = line;
		new->y = count;
		list = ft_get_list(list, curr, new);
		count++;
	}
	return (list);
}
