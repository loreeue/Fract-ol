NAME = fractol

SRC = events.c init.c main.c math_utils.c render.c aux_malloc.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

PURPLE = \033[1;35m
RESET = \033[0m

HEADER = "\n$(PURPLE)\
███████╗███████╗ █████╗  ██████╗████████╗ ██████╗ ██╗     \n\
██╔════╝██╔══██║██╔══██╗██╔════╝╚══██╔══╝██╔═══██╗██║     \n\
█████╗  ███████║███████║██║        ██║   ██║   ██║██║     \n\
██╔══╝  ████═╝  ██╔══██║██║        ██║   ██║   ██║██║     \n\
██║     ██  ██║ ██║  ██║╚██████╗   ██║   ╚██████╔╝███████╗\n\
╚═╝     ╚═════╝ ╚═╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚══════╝\n\
$(RESET)\n"

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

$(NAME): $(OBJ)
	@printf $(HEADER)
	@cd libft && $(MAKE) > /dev/null
	@cd $(MLX_DIR) && $(MAKE) > /dev/null 2>/dev/null
	@$(CC) $(CFLAGS) $(OBJ) -L ./libft -lft -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz -o $(NAME)
	@echo "Compilation complete!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@cd libft && $(MAKE) clean > /dev/null
	@cd $(MLX_DIR) && $(MAKE) clean > /dev/null
	@rm -f $(OBJ)
	@echo "Clean complete!"

fclean: clean
	@cd libft && $(MAKE) fclean > /dev/null
	@rm -f $(NAME)
	@echo "Full clean complete!"

all: $(NAME)

re: fclean all

.PHONY: clean fclean all re
