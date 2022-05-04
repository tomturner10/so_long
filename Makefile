
NAME = so_long

SRCS = so_long.c \
		map.c \
		map_utils.c \
		load_file.c \
		tiles.c \
		tile_type.c \
		utils/ft_itoa.c \
		utils/get_next_line.c \
		utils/get_next_line_utils.c


FLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -I Includes/utils -Lmlx -lmlx -Imlx -Ilst -Iutils -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)
	
clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re