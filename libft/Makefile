# Nombre de la librería final
NAME = libft.a

# Fuentes de libft
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c  ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c\
	ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c\
	ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c\
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	ft_atol.c ft_max.c ft_atodbl.c

SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c\
	ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

# Fuentes de ft_printf
PRINTF_DIR = ft_printf
PRINTF_SRC = $(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/ft_controls.c $(PRINTF_DIR)/ft_aux.c

# Objetos
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)

# Configuración de compilador y archivador
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

# Regla principal
$(NAME): $(OBJ) $(PRINTF_OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(PRINTF_OBJ)
	@echo "$(NAME) creado correctamente"

# Regla de compilación de objetos
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Regla para bonus
bonus: $(OBJ) $(OBJ_BONUS) $(PRINTF_OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ_BONUS) $(PRINTF_OBJ)
	@echo "$(NAME) con bonus creado correctamente"

# Limpieza de objetos
clean:
	@rm -f $(OBJ) $(OBJ_BONUS) $(PRINTF_OBJ)
	@echo "clean realizado correctamente"

# Limpieza total
fclean: clean
	@rm -f $(NAME)
	@echo "fclean realizado correctamente"

# Recompilar todo
all: $(NAME)

re: fclean all

rebonus: fclean all bonus

# Declarar reglas como PHONY
.PHONY: clean fclean all re bonus rebonus
