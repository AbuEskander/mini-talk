CC = cc 
CFLAGS = -Wall -Werror -Wextra -I./includes
SRCS = client.c
SRC_DIR = src
OBJ_DIR = build
SRCSDIR=$(addprefix src/,$(SRCS))
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o,$(SRCSDIR))
NAME = client
LIBFT = libft.a
all: $(NAME)

$(NAME):$(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -L. -lft -o $(NAME)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ) $(LIBFT)
fclean: clean
	rm -f $(NAME) 
re: fclean all

.PHONY: all clean fclean re