NAME=fract-ol
SRCS=$(shell ls *.c)
OBJS=$(SRCS:.c=.o)
all: $(NAME)
%.o: %.c
	$(CC) -O3 -Wall -Wextra -Werror -Iminilibx -Iheaders -c $< -o $@
$(NAME):	$(OBJS) complex.h window.h Makefile
	make -C minilibx
	cc -O3 $(OBJS) -Iminilibx minilibx/libmlx.a -Iheaders 			\
	-Wall -framework Foundation -isysroot `xcrun --show-sdk-path` 	\
	-framework Cocoa -framework OpenGL -o $(NAME)
m:	$(NAME)
	./fract-ol m
j:	$(NAME)
	./fract-ol j
clean:
	make clean -C minilibx
	rm -rf $(OBJS)
fclean:	clean
	rm -rf $(NAME)
re: fclean $(NAME)
