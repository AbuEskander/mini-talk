
CLIENT = client
SERVER_DIR = server_dir
CLIENT_DIR = client_dir
SERVER = server
NAME= miniTalk
LIBFT = libft
LIBFTA = libft.a

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@cp $(LIBFT)/$(LIBFTA) $(SERVER_DIR)
	@cp $(LIBFT)/$(LIBFTA) $(CLIENT_DIR)
	@make -C $(SERVER_DIR)
	@make -C $(CLIENT_DIR)
	@cp $(SERVER_DIR)/$(SERVER) .
	@cp $(CLIENT_DIR)/$(CLIENT) .
clean:
	@make -C $(SERVER_DIR) fclean
	@make -C $(CLIENT_DIR) fclean
	@make -C $(LIBFT) fclean
fclean: clean
	rm -f $(CLIENT) $(SERVER)
re: fclean all

.PHONY: all clean fclean re