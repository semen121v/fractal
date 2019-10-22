# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fshade <fshade@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/16 17:35:33 by eschoen           #+#    #+#              #
#    Updated: 2019/10/22 12:12:14 by fshade           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Имя конечного исполняемого файла
NAME = fractol

# Компилятор, флаги, подключение OpenG
COM = gcc
CFLAGS = -Wall -Wextra -Werror -g
LIBRARIES = -lmlx -lm -lft -L$(LIBFT_DIR) -L$(MINILIBX_DIR) -framework OpenGL -framework AppKit
INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS) -I$(FT_PRINTF_DIR)includes

# Папка с библиотекой libft
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_HEADERS = $(LIBFT_DIR)

# Папка с ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)libftprintf.a
FT_PRINTF_DIR = ./libft/ft_printf/
FT_PRINTF_HEADERS =	$(FT_PRINTF_DIR)includes

# Папка с библиотекой minilibX
MINILIBX = $(MINILIBX_DIR)libmlx.a
MINILIBX_DIR = ./minilibx_macos/
MINILIBX_HEADERS = $(MINILIBX_DIR)

# Папка с заголовочными файлами (*.h)
HEADERS_LIST = fractol.h
HEADERS_DIR = ./includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

# Папка с исходными С файлами (*.c)
SRCS_DIR = ./srcs/
SRCS_LIST = main.c fractol_drawing.c fractol_management.c mandatory_fractals.c \
			optional_fractals.c fractol_modification.c fractol_match_the_norme.c 
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))

# Папка с объектами (*.o)
OBJ_DIR = obj/
OBJ_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_LIST))

# Различные цвета для печатания текста при компиляции в консоль
RED = \033[0;31m
GREEN = \033[0;32m
PURPLE = \033[0;35m
WHITE = \033[0m
YELLOW = \033[0;33m

# Публикуем все правила в Makefile
.PHONY: all clean fclean re

# Комадны для компиляции:
all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(MINILIBX) $(OBJ_DIR) $(OBJ)
	@$(COM) $(CFLAGS) $(FT_PRINTF) $(LIBRARIES) $(INCLUDES) $(OBJ) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)object files has been created$(WHITE)"
	@echo "$(NAME): $(GREEN)$(NAME) has been succesfully created and ready for use !!!$(WHITE)"
	@echo "$(PURPLE)To launch the program, do like this: ./fractol [Fractol_name]$(WHITE)"
	@@echo "$(YELLOW)List of available Fractals - [ julia | mandelbrot | psych_spots | circle | cross | man | chiken ]"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(NAME): $(GREEN)$(OBJ_DIR) has been created$(WHITE)"

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c $(HEADERS)
	@$(COM) $(CFLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(WHITE)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Making $(LIBFT)...$(WHITE)"
	@$(MAKE) -sC $(LIBFT_DIR)

$(FT_PRINTF):
	@echo "$(NAME): $(GREEN)Making $(FT_PRINTF)...$(WHITE)"
	@$(MAKE) -sC $(FT_PRINTF_DIR)

$(MINILIBX):
	@echo "$(NAME): $(GREEN)Making $(MINILIBX)...$(WHITE)"
	@$(MAKE) -sC $(MINILIBX_DIR)

# Правило для запуска проверки на норму
norme:
	norminette ./$(LIBFT_DIR)/
	@echo
	norminette ./$(HEADERS_DIR)/
	@echo
	norminette ./$(SRCS_DIR)/
	@echo
	norminette ./$(FT_PRINTF_DIR)/

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(MAKE) -sC $(FT_PRINTF_DIR) clean
	@$(MAKE) -sC $(MINILIBX_DIR) clean
	@rm -rf $(OBJ_DIR)
	@rm -rf .DS_Store
	@rm -rf .vscode
	@rm -fr ./libft/libft.h.gch
	@echo "$(NAME): $(RED)$(OBJ_DIR) has been deleted$(WHITE)"
	@echo "$(NAME): $(RED)object files has been deleted$(WHITE)"

fclean: clean
	@rm -rf $(MINILIBX)
	@echo "$(NAME): $(RED)$(MINILIBX) has been deleted$(WHITE)"
	@rm -rf $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) has been deleted$(WHITE)"
	@rm -rf $(FT_PRINTF)
	@echo "$(NAME): $(RED)$(FT_PRINTF) has been deleted$(WHITE)"
	@rm -rf $(NAME)
	@echo "$(NAME): $(RED)$(NAME) has been deleted$(WHITE)"

re:
	@$(MAKE) fclean
	@$(MAKE) all