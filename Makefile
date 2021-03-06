LIBFT_OBJS	= ${LIBFT:%.c=%.o}

SRCS	=	main.c error_handler.c so_long.c utils.c utils2.c utils3.c \
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

INCLUDES	= so_long.h get_next_line/get_next_line.h
LIBFT_A		= libft/libft.a
MLX			= mlx/libmlx.a

OBJS	=	 ${SRCS:%.c=%.o}

NAME	=	so_long

CC		=	gcc
RM		=	rm -rf
CFLAGS	=	-Wall -Wextra -Werror

.PHONY:	all clean fclean re libft mlx

.o: .c 	${INCLUDES}
		${CC} ${CFLAGS} $< -o $@

all:	libft mlx ${NAME}

${NAME}: ${OBJS} ${INCLUDES}
	${CC} ${OBJS} ${LIBFT_A} ${MLX} -framework OpenGL -framework AppKit -o ${NAME}

libft:
	make -C libft

mlx:
	make -C mlx

clean:
	${RM} ${OBJS}
	make -C libft clean
	make -C mlx clean

fclean: clean
	${RM} ${NAME}
	make -C libft fclean
	make -C mlx fclean

re:	fclean all