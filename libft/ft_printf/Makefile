# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/23 00:30:05 by fallard           #+#    #+#              #
#    Updated: 2020/11/14 18:13:29 by sdonya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
parse.c \
print_result.c \
print_flags.c \
base.c \
pf_itoa.c \
dec_numbers.c \
dec_treatment.c \
specifier.c \
macros.c \
floats.c \
float_valide.c \
float_round_up.c \
long_arithmetic_int.c \
long_arithmetic_frac.c \
long_float_treatment.c \
print_bin.c \
print_iso_time.c \
print_iso_func.c \
helpers.c

TEMP = $(SRCS:.c=.o)

RD = \x1b[31m
GR = \x1b[32m
YW = \x1b[33m
BL = \x1b[34m
PK = \x1b[35m
CN = \x1b[36m
EOC = \x1b[0m

PF_H = -I .
LIB_H = -I ../libft.h

LIB = ..

all: $(NAME)

$(NAME): $(LIB)/libft.a $(TEMP)
	@ar rc $(NAME) $(TEMP)
	@printf "$(GR)LIBFTPRINTF SUCCESSFULLY COMPILED!\n$(EOC)"

%.o:%.c
	@gcc $(FLAGS) $(PF_H) $(LIB_H) -o $@ -c $< 

$(LIB)/libft.a:
	@printf "\n$(PK)COMPILING PROJECT...\n\n$(EOC)"
	@make -C $(LIB)
	@printf "$(GR)Libft.a compiled!\n$(EOC)"

clean: cleanlib
	@rm -f $(TEMP)
	@printf "$(YW)TEMP OBJECTS HAS BEED DELETED.\n$(EOC)"

fclean: clean fcleanlib
	@rm -f $(NAME)
	@printf "$(RD)LIBFTPRINTF, TEMP OBJECTS AND LIBFT HAS BEEN DELETED.\n$(EOC)"

re: fclean all

cleanlib:
	@make clean -C $(LIB)

fcleanlib:
	@make fclean -C $(LIB)
