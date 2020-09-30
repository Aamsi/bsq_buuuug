/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 09:21:44 by iouali            #+#    #+#             */
/*   Updated: 2020/09/30 17:53:24 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <libc.h>

typedef struct	s_plat_info
{
	int		nb_lines;
	int		nb_columns;
	int		x;
	int		y;
	int		best_size;
	char	empty_char;
	char	obstacle;
	char	filler;
	char	**matrix;
}				t_plat_info;

typedef struct	s_tester
{
	int			x;
	int			y;
	int			x_bis;
	int			y_bis;
}				t_tester;

void			print_matrix(t_plat_info datas, char **tab, int ac, int i);
void			ft_str(char *str);
void			free_all_ok(char **strs, char *str);
void			free_strs(char **strs);
void			debug_matrix(char **strs);
void			print_info(t_plat_info infos);
char			**ft_split(char *str, char *charset);
char			**get_new_matrix(char **strs);
char			**fill_soluce(t_plat_info datas, char **tab);
char			**free_split(char **strs, int j);
char			*ft_realloc(char *ptr, int size);
char			*ft_strdup(char *src);
int				ft_atoi(char *str, int index);
int				ft_len(char *str);
int				ft_len_strs(char **strs);
int				count_charac(char *filename);
int				check_first_line(char *str);
int				nb_columns(char **matrix);
int				check_nb_lines(char **matrix, int nb_lines);
int				check_charac(char **matrix, char obst, char empty);
int				free_struct(t_plat_info infos);
t_plat_info		solver(t_plat_info datas);
t_plat_info		parsing(char *filename);
t_plat_info		reterror(t_plat_info infos, int ertyp, char *big_str,
						char **matrix);
t_plat_info		turbo_tester(t_plat_info datas, int i, int j);
t_plat_info		parsing_stdin();

#endif
