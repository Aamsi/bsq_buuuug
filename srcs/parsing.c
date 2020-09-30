/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 09:07:48 by iouali            #+#    #+#             */
/*   Updated: 2020/09/30 11:47:54 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_plat_info		assign_el(char **matrix, char *first_line)
{
	int			len_fl;
	t_plat_info	infos;

	infos.matrix = 0;
	len_fl = ft_len(first_line);
	infos.filler = first_line[len_fl - 1];
	infos.obstacle = first_line[len_fl - 2];
	infos.empty_char = first_line[len_fl - 3];
	infos.nb_lines = ft_atoi(first_line, ft_len(first_line) - 3);
	infos.best_size = 0;
	infos.x = 0;
	infos.y = 0;
	infos.matrix = get_new_matrix(matrix);
	infos.nb_columns = nb_columns(infos.matrix);
	return (infos);
}

int				check_same_nb_col(char **matrix)
{
	int i;

	i = 1;
	while (matrix[i])
	{
		if (ft_len(matrix[i]) != ft_len(matrix[i - 1]))
			return (0);
		i++;
	}
	return (1);
}

t_plat_info		get_all_infos(char *str)
{
	char		**matrix;
	t_plat_info	infos;

	matrix = 0;
	infos.matrix = 0;
	if (!(matrix = ft_split(str, "\n")))
		return (reterror(infos, 1, str, matrix));
	if (ft_len_strs(matrix) <= 1)
		return (reterror(infos, 2, str, matrix));
	if (!(check_first_line(matrix[0])))
		return (reterror(infos, 2, str, matrix));
	infos = assign_el(matrix, matrix[0]);
	if ((check_nb_lines(infos.matrix, infos.nb_lines)) != 0)
		return (reterror(infos, 2, str, matrix));
	if (!(check_charac(infos.matrix, infos.obstacle, infos.empty_char)))
		return (reterror(infos, 2, str, matrix));
	if (!(check_same_nb_col(infos.matrix)))
		return (reterror(infos, 2, str, infos.matrix));
	if ((infos.empty_char == infos.filler) ||
		infos.empty_char == infos.obstacle ||
		infos.obstacle == infos.filler)
		return (reterror(infos, 2, str, matrix));
	return (infos);
}

t_plat_info		parsing(char *filename)
{
	char			*big_str;
	int				fd;
	int				nb_charac;
	int				ret;
	t_plat_info		infos;

	infos.matrix = 0;
	big_str = 0;
	if (!(nb_charac = count_charac(filename)))
		return (reterror(infos, 0, big_str, infos.matrix));
	if (nb_charac < 4)
		return (reterror(infos, 0, big_str, infos.matrix));
	if (!(big_str = malloc(nb_charac)))
		return (reterror(infos, 0, big_str, infos.matrix));
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (reterror(infos, 1, big_str, infos.matrix));
	if ((ret = read(fd, big_str, nb_charac)) < 1)
		return (reterror(infos, 1, big_str, infos.matrix));
	big_str[ret] = '\0';
	if (big_str[ret - 1] != '\n')
		return (reterror(infos, 1, big_str, infos.matrix));
	infos = get_all_infos(big_str);
	return (infos);
}
