
NAME	= so_long

SRCS	= so_long.c chekmap.c error.c hook.c image.c init_map.c init_sprit.c ./getnextline/get_next_line.c ./getnextline/get_next_line_utils.c chekmap2.c

RM		= rm -f

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address

PRINTF_A = ./printf/libftprintf.a

PRINTF	= ./printf

MLX = ./mlx

MLX_A = ./mlx/libmlx.a

MLX_FLAG = -I ${MLX} -L ${MLX} -lmlx -framework OpenGL -framework AppKit

all:		${NAME}

$(NAME): $(SRCS) ${PRINTF_A} ${MLX_A}
	$(CC) $(CFLAGS) $(SRCS) ${PRINTF_A} ${MLX_FLAG} -o $(NAME)

${PRINTF_A}:
	make -C ${PRINTF}

${MLX_A}:
	make -C ${MLX}

clean:		
			make clean -C ${PRINTF}
			make clean -C ${MLX}

fclean:		clean
			${RM} ${NAME}
			make fclean -C ${PRINTF}

re:			fclean all