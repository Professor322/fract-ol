COMPILER = gcc
CHECK_FLAGS = -Wall -Wextra #-Werror
NAME = fract-ol
ADD_SRC = ./src/
RESOURCES = main.c
SRC_S = $(addprefix $(ADD_SRC), $(RESOURCES))
OBJ = $(SRC_S:.c=.o)
ADD_INC = ./includes/
ADD_LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME):  $(OBJ)
	@make  -C ./libft all
	@$(COMPILER) -o $(NAME) $(CHECK_FLAGS) $(COMPILE_FLAGS) $(OBJ) $(ADD_LIBFT)
	@echo ======[Done]======
%.o : %.c
	@echo "$(NAME) >>> Add/Update $<"
	@$(COMPILER) -c -o $@ -I $(ADD_INC) -I ./libft/includes $(CHECK_FLAGS) $<
clean:
	@rm -f $(ADD_SRC)*.o
	@make  -C ./libft clean
fclean: clean
	@rm -f ./$(NAME)
	@make -C ./libft fclean
re: fclean all