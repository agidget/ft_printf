NAME	=	libftprintf.a
HEADER	=	ft_printf.h
LIST	=	flags_parser.c\
			for_print_stuff.c\
			ft_itoa_uns.c\
			ft_itoa.c\
			ft_printf.c\
			functions.c\
			print_char.c\
			print_int.c\
			print_neg_int.c\
			print_percent.c\
			print_pointer.c\
			print_pos_int.c\
			print_string.c\
			print_unsign_int.c\
			print_x.c\
			print_xx.c
CC		=	gcc
OBJ		=	$(patsubst %.c,%.o,$(LIST))

RM		=	rm -rf
OPT_F	=	-O2
CFLAGS	=	-Wall -Werror -Wextra
			
all:	${NAME}

$(NAME):	$(OBJ) $(HEADER) 
	ar rcs $(NAME) $?

%.o: %.c
	$(CC) $(CFLAGS) $(OPT_F) -c $< -o $@

clean:
					$(RM) $(OBJ) $(OBJ_B)
fclean:				clean
					$(RM) $(NAME)
re:					fclean all
.PHONY:				all clean fclean re bonus
