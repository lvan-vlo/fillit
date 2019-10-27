/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 15:36:50 by twoerdem       #+#    #+#                */
/*   Updated: 2019/02/23 15:40:53 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 42
# include <fcntl.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct			s_tetris
{
	char				**content;
	size_t				x;
	size_t				y;
	struct s_tetris		*next;
}						t_tetris;

char					*ft_read_tetriminos(int fd, char *file);
int						ft_check_file(char *file);
char					**ft_make_tet(char *file);
void					ft_fill_list(char *file);
char					*ft_strchr_y(char **array, int x, char c);
void					ft_print_map(char **map);
char					**replace_character(char **array, int c);
void					ft_fillit(t_tetris *head, int mapsize);
void					ft_delmap(char **map);
void					ft_del_tetri(t_tetris *head);
int						ft_set_y(char **tetris);
char					**ft_map_make(int mapsize);

#endif
