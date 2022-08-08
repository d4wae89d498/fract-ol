NAME=fract-ol
SRCS=main.c math1.c math2.c window1.c window2.c fractals.c\
	charbon.c\
	charbon2.c\
	mandlebrot.c\
	julia.c
OBJS=$(SRCS:.c=.o)
CFLAGS=-Wall -Wextra -Werror -Iminilibx # -O3 -g
all: $(NAME)
%.o: %.c  fractals.h mymath.h window.h Makefile minilibx/libmlx.a 
	$(CC) $(CFLAGS) -c $< -o $@
minilibx/libmlx.a: 
	make -C minilibx
$(NAME): draw_fractals.c $(OBJS) draw_fractals.o  
	cc $(CFLAGS) $(OBJS) draw_fractals.o minilibx/libmlx.a \
	-Wall -framework Foundation -isysroot `xcrun --show-sdk-path` \
	-framework Cocoa -framework OpenGL -o $(NAME)
bonus:  draw_fractals_bonus.c $(OBJS) draw_fractals_bonus.o
	cc $(CFLAGS) $(OBJS) draw_fractals_bonus.o minilibx/libmlx.a \
	-Wall -framework Foundation -isysroot `xcrun --show-sdk-path` \
	-framework Cocoa -framework OpenGL -o $(NAME)
clean:
	make -C minilibx $@
	rm -rf $(OBJS) draw_fractals.o draw_fractals_bonus.o
fclean:	clean
	rm -rf $(NAME)
re: fclean $(NAME)
