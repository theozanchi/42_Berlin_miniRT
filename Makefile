NAME = miniRT

CC = cc

SRCS := $(wildcard src/*.c) $(wildcard src/**/*.c)

CFLAGS = -Wall -Werror -Wextra -g

LIBFLAGS = -lmlx -lXext -lX11 -lm

INCLUDE = -L ./minilibx

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(MAKE) -C minilibx
	$(CC) $(CFLAGS) $(LIBFLAGS) $(OBJS) ./libft/libft.a ./minilibx/libmlx.a -o $(NAME)

.c.o:
	$(CC) -g $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx clean
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	$(MAKE) -C minilibx fclean
	rm -rf $(NAME)

re: fclean all

phony: all clean fclean re