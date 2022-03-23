NAME=fract-ol
SRCS=$(shell ls *.c)
OBJS=$(SRCS:.c=.o)
all: $(NAME)

all:	$(NAME)
%.o: %.c
	$(CC) -g -Wall -Wextra -Werror -Iminilibx -Iheaders -c $< -o $@
$(NAME):	$(OBJS)
	make -C minilibx
	cc -g $(OBJS) -Iminilibx minilibx/libmlx.a -Iheaders 			\
	-Wall -framework Foundation -isysroot `xcrun --show-sdk-path` 	\
	-framework Cocoa -framework OpenGL -o $(NAME) 					\
	&& ./$(NAME) m
clean:
	make clean -C minilibx
	rm -rf $(OBJS)
fclean:	clean
	rm -rf $(NAME)
.PHONY: mlx
