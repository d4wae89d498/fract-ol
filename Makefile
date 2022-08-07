NAME=fract-ol
SRCS=main.c fractals.c math1.c math2.c window1.c window2.c\
	charbon.c\
	mandlebrot.c\
	julia.c
OBJS=$(SRCS:.c=.o)
CFLAGS=-Wall -Wextra -Werror -Iminilibx -Iheaders -Dftype="float"#-O3 -g
all: $(NAME)
%.o: %.c  mymath.h window.h Makefile minilibx/libmlx.a 
	$(CC) $(CFLAGS) -c $< -o $@
minilibx/libmlx.a: 
	make -C minilibx
$(NAME):	$(OBJS) 
	cc $(CFLAGS) $(OBJS) minilibx/libmlx.a \
	-Wall -framework Foundation -isysroot `xcrun --show-sdk-path` \
	-framework Cocoa -framework OpenGL -o $(NAME)
clean:
	make -C minilibx $@
	rm -rf $(OBJS)
fclean:	clean
	rm -rf $(NAME)
re: fclean $(NAME)
