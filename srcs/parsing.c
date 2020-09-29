/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 09:07:48 by iouali            #+#    #+#             */
/*   Updated: 2020/09/29 12:02:47 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		count_charac(char *filename)
{
	int		fd;
	char	buf[1];
	int		nb_charac;

	nb_charac = 0;
	if ((fd = open(filename, O_RDONLY)) <= 0)
		return (0);
	while (read(fd, buf, 1) > 0)
		nb_charac++;
	close(fd);
	return (nb_charac);
}

int		check_first_line(char *str)
{
	int i;
	int nb_len;

	i = ft_len(str);
	if (i < 4)
		return (0);
	i--;
	while (i >= 0)
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		i--;
	}
	nb_len = ft_len(str) - 3;
	i = 0;
	while (i < nb_len)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

t_plat_info		assign_el(char **matrix, char *first_line)
{
	int			i;
	int			len_fl;
	t_plat_info	infos;

	len_fl = ft_len(first_line);
	infos.filler = first_line[len_fl - 1];
	infos.obstacle = first_line[len_fl - 2];
	infos.empty_char = first_line[len_fl - 3];
	infos.nb_lines = ft_atoi(first_line, ft_len(first_line) - 3);
	infos.best_size = 0;
	infos.x = 0;
	infos.y = 0;
	infos.matrix = get_new_matrix(matrix);
	return (infos);
}

int				check_nb_lines(char **matrix, int nb_lines)
{
	int i;

	i = 0;
	while (matrix[i])
		i++;
	return (i - nb_lines);
}

int				check_charac(char **matrix, char obst, char empty)
{
	int i;
	int j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] != obst && matrix[i][j] != empty)
				return (0);
			j++;
		}
		i++;
	}
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

	if (!(matrix = ft_split(str, "\n")))
		return ;
	if (!(check_first_line(matrix[0])))
		return ;
	infos = assign_el(matrix, matrix[0]);
	if ((check_nb_lines(infos.matrix, infos.nb_lines)) != 0)
		return ;
	if (!(check_charac(infos.matrix, infos.obstacle, infos.empty_char)))
		return ;
	if (!(check_same_nb_col(infos.matrix)))
		return ;
	if ((infos.empty_char == infos.filler) || infos.empty_char == infos.obstacle || infos.obstacle == infos.filler)
		return ;
	return (infos);
}

int		parsing(char *filename)
{
	char	*big_str;
	t_plat_info		infos;
	int		fd;
	int		nb_charac;

	nb_charac = count_charac(filename);
	if (!(big_str = malloc(nb_charac + 1)))
		return (0);
	if ((fd = open(filename, O_RDONLY)) <= 0)
		return (0);
	if ((read(fd, big_str, nb_charac)))
	if (!(infos = get_all_infos(big_str)))
		return (0);
	return (1);
}
