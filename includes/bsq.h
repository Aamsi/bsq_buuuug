/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 09:21:44 by iouali            #+#    #+#             */
/*   Updated: 2020/09/29 19:15:17 by iouali           ###   ########.fr       */
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

void			print_matrix(t_plat_info datas, char **tab);
void			ft_putstr(char *str);
char			**ft_split(char *str, char *charset);
char			**get_new_matrix(char **strs);
char			**fill_soluce(t_plat_info datas, char **tab);
char			*ft_strdup(char *src);
int				ft_atoi(char *str, int index);
int				ft_len(char *str);
int				ft_len_strs(char **strs);
t_plat_info		solver(t_plat_info datas);
t_plat_info		parsing(char *filename);

#endif
