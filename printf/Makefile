NAME            =   libftprintf.a

CC              =   gcc
CFLAGS          =   -Wall -Wextra -Werror -g3
AR              =   ar
ARFLAGS         =   rcs
RM              =   rm -rf

SRC             =   ft_printf.c ft_printf_c.c ft_printf_s.c ft_printf_x.c ft_printf_d.c ft_printf_p.c ft_printf_u.c
SRCS            =   $(SRC)

OBJ_DIR         =   obj
OBJS            =   $(SRCS:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all:            $(NAME)

bonus:          all

$(NAME):        $(OBJ_DIR) $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean:         clean
	$(RM) $(NAME)

re:             fclean all

.PHONY:         all bonus clean fclean re
