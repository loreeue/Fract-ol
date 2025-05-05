NAME = fractol

SRC = events.c init.c main.c math_utils.c render.c aux_malloc.c color.c

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR)

MLX_DIR = minilibx-linux

$(NAME): $(OBJ)
	@cd libft && $(MAKE) > /dev/null
	@cd $(MLX_DIR) && $(MAKE) > /dev/null 2>/dev/null
	@$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz -o $(NAME)
	@echo "Compilation complete!"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@cd libft && $(MAKE) clean > /dev/null
	@cd $(MLX_DIR) && $(MAKE) clean > /dev/null
	@rm -rf $(OBJ_DIR)
	@echo "Clean complete!"

fclean: clean
	@cd libft && $(MAKE) fclean > /dev/null
	@rm -f $(NAME)
	@echo "Full clean complete!"

all: $(NAME)

re: fclean all

.PHONY: clean fclean all re
