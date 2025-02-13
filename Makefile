NAME := so_long
CC := cc
CFLAGS := -Wextra -Wall -Werror -g
LIBMLX := ./MLX42
LIBFT_DIR := ft_libft
PRINTF_DIR := ft_printf
GNL_DIR := get_next_line
LIBFT := $(LIBFT_DIR)/libft.a
PRINTF := $(PRINTF_DIR)/libftprintf.a
GNL := $(GNL_DIR)/get_next_line.a

HEADERS := -I ./include -I $(LIBMLX)/include
LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRC_DIR := ./src
SRCS := $(SRC_DIR)/free_player.c \
        $(SRC_DIR)/hooks.c \
        $(SRC_DIR)/map_errors.c \
        $(SRC_DIR)/map_utils_2.c \
        $(SRC_DIR)/map_utils.c \
        $(SRC_DIR)/player_movement.c \
        $(SRC_DIR)/player_movement2.c \
        $(SRC_DIR)/player_utils.c \
        $(SRC_DIR)/resource_manager.c \
        $(SRC_DIR)/resource_manager2.c \
        $(SRC_DIR)/utils.c \
        $(SRC_DIR)/so_long.c

OBJS := ${SRCS:.c=.o}

all: libmlx $(LIBFT) $(PRINTF) $(GNL) $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT):
	@echo "Compiling libft..."
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@echo "Compiling ft_printf..."
	@make -C $(PRINTF_DIR)

$(GNL):
	@echo "Compiling get_next_line..."
	@make -C $(GNL_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(GNL)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) $(LIBFT) $(PRINTF) $(GNL)
	@echo "Compilation of $(NAME) complete."

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
	@make -C $(GNL_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	@make -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libmlx
