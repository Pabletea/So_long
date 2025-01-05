NAME = test_window
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
MLX = mlx
MLX_FLAGS = -L$(MLX) -lmlx -L/usr/lib -lXext -lX11 -lm -lz
INCLUDES = -I/usr/include -I$(MLX)
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
