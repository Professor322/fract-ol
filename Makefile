COMPILER = gcc
CHECK_FLAGS= -Wall -Wextra #-Werror
COMPILE_FLAGS= -lmlx_Linux -lXext -lX11 -O3
NAME = fract-ol
ADD_SRC = ./src/
RESOURCES = main.c
SRC_S = $(addprefix $(ADD_SRC), $(RESOURCES))
OBJ = $(SRC_S:.c=.o)
ADD_INC = ./includes/
ADD_LIBFT_INC = ./libft/includes/
ADD_MLX_INC = ./minilibx/

all: $(NAME)

$(NAME):  $(OBJ)
	@make  -C ./libft all
	$(COMPILER) $(OBJ) $(CHECK_FLAGS) $(COMPILE_FLAGS) -I $(ADD_INC) -I $(ADD_LIBFT_INC) -I $(ADD_MLX_INC) -L $(ADD_MLX_INC) -o $(NAME)
	@echo ======[Done]======
%.o : %.c
	@echo "$(NAME) >>> Add/Update $<"
	$(COMPILER) -c -o $@ $(CHECK_FLAGS) $(COMPILE_FLAGS) -I $(ADD_INC) -I $(ADD_LIBFT_INC) -I $(ADD_MLX_INC) -L $(ADD_MLX_INC) $<

clean:
	@rm -f $(ADD_SRC)*.o
	@make  -C ./libft clean
fclean: clean
	@rm -f ./$(NAME)
	@make -C ./lib