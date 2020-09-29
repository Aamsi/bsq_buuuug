/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 09:21:44 by iouali            #+#    #+#             */
/*   Updated: 2020/09/29 18:22:11 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <libc.h>

typedef struct	s_plat_info
{
	int		nb_lines;
	char	empty_char;
	char	obstacle;
	char	filler;
	char	**matrix;
	int		x;
	int		y;
	int		best_size;
}				t_plat_info;

char	**ft_split(char *str, char *charset);
char	**get_new_matrix(char **strs);
char	*ft_strdup(char *src);
int		ft_atoi(char *str, int index);
int		ft_len(char *str);
int		ft_len_strs(char **strs);

#endif
