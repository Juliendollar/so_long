NAME					=	so_long
NAME_BONUS				=	so_long_bonus

CC						=	gcc
CFLAGS					=	-Wall -Wextra -Werror -g3 -MMD
RM						=	rm -rf

SRCBAZ					=	so_long check_map check_map2 check_path free_exit image
SRC						=	$(addsuffix .c, $(addprefix sources/, $(SRCBAZ)))


OBJ_DIR					=	obj
OBJ						=	$(SRC:sources/%.c=$(OBJ_DIR)/%.o)

INCLS					=	-I ./includes/ -I ./libft -I ./minilibx-linux/

LIBFT_PATH				=	./libft
LIBFT					=	$(LIBFT_PATH)/libft.a
LIBINCL					=	-L $(LIBFT_PATH) -lft

MLX_PATH				=	./minilibx-linux
MLX						=	$(MLX_PATH)/libmlx_Linux.a
MLXFLAGS				=	-L $(MLX_PATH) -lmlx -lXext -lX11

DEPS					=	$(OBJ:%.o=%.d)

$(OBJ_DIR)/%.o: sources/%.c
						$(CC) $(CFLAGS) $(INCLS) -c $< -o $@

all:					$(NAME)
						@echo "\033[32m[Programme prêt à l'emploi]\033[0m"

$(NAME):				$(LIBFT) $(OBJ_DIR) $(OBJ)
						$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBINCL) $(MLXFLAGS)
						@echo "\033[32m[so_long créé]\033[0m"

$(LIBFT):
						$(MAKE) -C $(LIBFT_PATH) all

$(OBJ_DIR):
						mkdir -p $(OBJ_DIR)

clean:
						$(RM) $(OBJ_DIR)
						@echo "\033[33m[Nettoyé]\033[0m"

fclean:					clean
						$(MAKE) -C $(LIBFT_PATH) fclean
						$(RM) $(NAME)
						@echo "\033[33m[Suppression totale]\033[0m"

re:						fclean all