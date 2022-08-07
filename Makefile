NAME=fract-ol
SRCS=main.c math1.c math2.c math3.c window1.c window2.c\
	charbon.c\
	mandlebrot.c\
	julia.c
OBJS=$(SRCS:.c=.o)
CFLAGS=-Wall -Wextra -Werror -Iminilibx -Iheaders -Dftype="float" -DTHREADS=40 -DCOLOR_SHIFT=1#-O3 -g
all: $(NAME)
%.o: %.c  mymath.h window.h Makefile minilibx/libmlx.a 
	$(CC) $(CFLAGS) -c $< -o $@
minilibx/libmlx.a: 
	make -C minilibx
$(NAME):	$(OBJS) fractals.o  
	cc $(CFLAGS) $(OBJS) fractals.o minilibx/libmlx.a \
	-Wall -framework Foundation -isysroot `xcrun --show-sdk-path` \
	-framework Cocoa -framework OpenGL -o $(NAME)
bonus:  fractals_bonus.c mymath.h window.h Makefile minilibx/libmlx.a $(OBJS) fractals_bonus.o
	cc $(CFLAGS) $(OBJS) fractals_bonus.o minilibx/libmlx.a \
	-Wall -framework Foundation -isysroot `xcrun --show-sdk-path` \
	-framework Cocoa -framework OpenGL -o $(NAME)
clean:
	make -C minilibx $@
	rm -rf $(OBJS) fractals.o fractals_bonus.o
fclean:	clean
	rm -rf $(NAME)
re: fclean $(NAME)
