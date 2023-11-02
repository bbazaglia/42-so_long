NAME = game
VPATH = src: ./src
SRC = chained.c \
	  math-of.c \
	  image.c \
	  object.c \
	  game.c \
	  main.c
INCLUDE = -I./include
OBJ = obj
SRCOBJ = $(SRC:%.c=${OBJ}/%.o)
ifneq ($(OS), Windows_NT)
	CREATE = mkdir -p $(1)
	REMOVE = rm -rf $(1)
endif

all: $(NAME)
$(NAME): $(SRCOBJ)
	$(CC) $^ -o $(NAME)
${OBJ}/%.o : %.c
	$(call CREATE, ${OBJ})
	$(CC) -c $< -o $@ $(INCLUDE)
valgrind:
	valgrind --leak-check=full -q ./${NAME}
clean:
	$(call REMOVE, ${OBJ}/*.o)
fclean: clean
	$(call REMOVE, ${NAME})
re: fclean all