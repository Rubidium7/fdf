NAME = fdf

SRC_PATH = src
OBJ_PATH = obj

SRC_NAME = main.c print_fdf.c draw_lines.c youre_up_and_youre_down.c colors.c mlx_utils.c utils.c utils2.c
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

LIB = libft/libft.a
PRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(LIB):
	make all -C libft
	make bonus -C libft

$(PRINTF):
	make all -C ft_printf

$(NAME): $(LIB) $(PRINTF) $(OBJ)
	cc -lmlx -lm -framework OpenGL -framework AppKit -o $@ $^

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@cc -Wall -Werror -Wextra -Imlx -o $@ -c $<

clean:
	make fclean -C libft
	make fclean -C ft_printf
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -f $(NAME)

re: fclean all
