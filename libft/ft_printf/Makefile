NAME = libftprintf.a

SRC = ft_printf.c ft_aux.c ft_controls.c
OBJ = $(SRC:.c=.o)
INCLUDE = ft_printf.h

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

$(NAME): $(OBJ) $(INCLUDE)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@echo "$(NAME) creado correctamente"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "clean realizado correctamente"

fclean: clean
	rm -f $(NAME)
	@echo "fclean realizado correctamente"

all: $(NAME)

re:	fclean all

.PHONY: clean fclean all re
