.PHONY = all clean fclean re

FRACTOLS = Mandatory/fractal/

SRCS = Mandatory/srcs/

UTILS = Mandatory/utils/

FRACTOLS_BONUS = Bonus/fractal/

SRCS_BONUS = Bonus/srcs/

UTILS_BONUS = Bonus/utils/

SRC = $(addprefix $(SRCS), main.c libft.c ft_checker.c)

UTIL = $(addprefix $(UTILS), hooks.c mouse_hooks.c output.c print_pxl.c utils_hooks.c zoom.c) 

FRACTOL = $(addprefix $(FRACTOLS), mandelbrot_main.c mandelbrot_healper.c julia_main.c julia_helper.c)

SRC_BONUS = $(addprefix $(SRCS_BONUS), main_bonus.c libft_bonus.c ft_checker_bonus.c)

UTIL_BONUS = $(addprefix $(UTILS_BONUS), hooks_bonus.c mouse_hooks_bonus.c output_bonus.c print_pxl_bonus.c utils_hooks_bonus.c zoom_bonus.c) 

FRACTOL_BONUS = $(addprefix $(FRACTOLS_BONUS), burning_helper_bonus.c burning_main_bonus.c mandelbrot_main_bonus.c mandelbrot_healper_bonus.c julia_main_bonus.c julia_helper_bonus.c)

OBJ = $(SRC:.c=.o)

OBJ_UT = $(UTIL:.c=.o)

OBJ_FCT = $(FRACTOL:.c=.o)


OBJ_BONUS = $(SRC_BONUS:.c=.o)

OBJ_UT_BONUS = $(UTIL_BONUS:.c=.o)

OBJ_FCT_BONUS = $(FRACTOL_BONUS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	@$(CC) $(CFLAGS) -c -g  $< -o $@

NAME = fractol

BONUS_NAME = fractol_bonus

all: fclean ${NAME} clean

$(NAME): $(OBJ) $(OBJ_UT) $(OBJ_FCT)
	@$(CC) $(OBJ) $(OBJ_UT) $(OBJ_FCT) -lmlx -framework OpenGL -fsanitize=address -framework AppKit -o $(NAME)
	@echo [MANDATORY COMPLET]

bonus: fclean ${BONUS_NAME} clean

$(BONUS_NAME): $(OBJ_BONUS) $(OBJ_UT_BONUS) $(OBJ_FCT_BONUS)
	@$(CC) $(OBJ_BONUS) $(OBJ_UT_BONUS) $(OBJ_FCT_BONUS) -lmlx -framework OpenGL -fsanitize=address -framework AppKit -o $(BONUS_NAME)
	@echo [BONUS COMPLET]

clean:
	@$(RM) $(OBJ_BONUS) $(OBJ_UT_BONUS) $(OBJ_FCT_BONUS)
	@$(RM) $(OBJ) $(OBJ_UT) $(OBJ_FCT)
	@echo [CLEAN OBJ FILES]

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)
	@echo [CLEAN ALL IS COMPLET]

re: fclean all