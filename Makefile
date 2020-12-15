# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgamora <cgamora@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/24 15:15:06 by cgamora           #+#    #+#              #
#    Updated: 2020/11/14 18:13:29 by sdonya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC = main.c args_sort.c fit_ls.c get_flagl.c list_getter.c list_sort.c parse.c \
		print_all.c print_list.c
OBJ = $(SRC:.c=.o)
HEADER = -I includes/ft_ls.h
INCLUDE_LIB = libft/
INCLUDE_PRF = libft/ft_printf/
FLAGS = -c -Wall -Wextra -Werror
OBJ_DIR = ./obj
SRC_DIR = ./src

OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

all: do_lib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) $(HEADER) -c $< -o $@

$(NAME): $(OBJS)
	@gcc $(OBJS) -L $(INCLUDE_LIB) -lft -L $(INCLUDE_PRF) -lftprintf -o $(NAME)

do_lib:
		@make -C ./libft/ft_printf/

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make -C libft/ clean
	@make -C libft/ft_printf/ clean

fclean: clean
	@make -C libft/ fclean
	@make -C libft/ft_printf/ fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re