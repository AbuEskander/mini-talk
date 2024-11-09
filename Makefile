SRC_DIR = src
OBJ_DIR = build
CC = cc
CFLAGS = -Wall -Werror -Wextra -I./includes
NAME = minitalk
SRCS_server = server.c
SRCS_client = client.c
SERVER = server
CLIENT = client
SRCSDIR_server=$(addprefix src/,$(SRCS_server))
SRCSDIR_client = $(addprefix src/,$(SRCS_client))
OBJS_server = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCSDIR_server))
OBJS_client = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCSDIR_client))
LIBFT = libft

all: $(NAME)

$(NAME): $(OBJS_server) $(OBJS_client)
	@make -C $(LIBFT)
	@cp $(LIBFT)/$(LIBFT).a .
	$(CC) $(OBJS_client) $(CFLAGS) -L. -lft -o $(CLIENT)
	$(CC) $(OBJS_server) $(CFLAGS) -L. -lft -o $(SERVER)
	

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
clean: 
	@make -C $(LIBFT) fclean
	rm -f  $(OBJS_client) $(OBJS_server) $(LIBFT).a

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re