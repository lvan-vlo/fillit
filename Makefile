# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/07 15:36:54 by twoerdem       #+#    #+#                 #
#    Updated: 2019/02/25 18:35:56 by lvan-vlo      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC =	ft_fillit.c \
		ft_strchr_y.c \
		ft_map_tetriminos.c \
		ft_fill_list.c \
		ft_check_file.c \
		ft_read_tetriminos.c \
		ft_print_map.c \
		frees.c \
		main.c
OBJ =	ft_fillit.o \
		ft_strchr_y.o \
		ft_map_tetriminos.o \
		ft_fill_list.o \
		ft_check_file.o \
		ft_read_tetriminos.o \
		ft_print_map.o \
		frees.o \
		main.o
LIBFT = -L./libft -lft
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@gcc -c $(FLAGS) $(SRC)
	@gcc -o $(NAME) $(FLAGS) $(SRC) $(LIBFT)

clean:
	@make -C libft/ fclean
	@rm -f *.o

fclean: clean
	@rm -f ./$(NAME)

re: fclean all
