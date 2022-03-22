NAME=fract-ol
SRCS=$(shell ls *.c)
OBJS=$(SRCS:.c=.o)
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Iminilibx -c $< -o $@

$(NAME):	$(OBJS)
	cc $(OBJS) minilibx/libmlx.a \
	-Wall -framework Foundation -isysroot `xcrun --show-sdk-path` \
	-framework Cocoa -framework OpenGL \
	&& ./a.out
