##
## EPITECH PROJECT, 2023
## makefile
## File description:
## Write a Makefile that compiles your libmy.
##

SRC	=	my_find_prime_sup.c \
		my_is_prime.c  \
		my_putstr.c  \
		my_showstr.c \
		my_strcapitalize.c \
		my_strcpy.c \
		my_str_isnum.c \
		my_strlen.c \
		my_strncmp.c \
		my_compute_power_rec.c \
		my_getnbr.c \
		my_putchar.c \
		my_revstr.c \
		my_show_word_array.c \
		my_strcat.c \
		my_str_isalpha.c \
		my_str_isprintable.c \
		my_strlowcase.c \
		my_strncpy.c \
		my_strupcase.c \
		my_compute_square_root.c \
		my_isneg.c \
		my_put_nbr.c \
		my_showmem.c \
		my_sort_int_array.c \
		my_strcmp.c \
		my_str_islower.c \
		my_str_isupper.c \
		my_strncat.c \
		my_strstr.c \
		my_strdup.c \
		my_swap.c \
		my_nbr_to_str.c	\
		display_error.c \
		my_str_to_word_array.c \
		my_nbr_to_str.c	\
		my_str_is_alpha_num.c	\
		display_string_colored.c	\
		clean_format.c	\
		my_realloc.c	\
		string_format.c

CPPFLAGS	=	-I.

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME) clean

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	mv $(NAME) ..

clean:
	@rm -f $(OBJ)
	@rm -f *~
	@rm -f *.gcda
	@rm -f *.gcno

fclean:	clean
	@rm -f $(NAME)
	@rm -f ../$(NAME)

re:	fclean all
