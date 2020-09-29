/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 09:07:48 by iouali            #+#    #+#             */
/*   Updated: 2020/09/29 22:21:29 by iouali           ###   ########.fr       */
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
	//printf("%d\n", i);
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
		i++;
	}
	return (1);
}

int				nb_columns(char **matrix)
{
	int i;

	i = 0;
	if (!matrix[0])
		return (i);
	while(matrix[0][i])
		i++;
	return (i);
}

t_plat_info		assign_el(char **matrix, char *first_line)
{
	int			len_fl;
	t_plat_info	infos;

	infos.matrix = 0;
	len_fl = ft_len(first_line);
	infos.filler = first_line[len_fl - 1];
	// printf("infos_filler: %c\n", infos.filler);
	infos.obstacle = first_line[len_fl - 2];
	// printf("infos_obstacle: %c\n", infos.obstacle);
	infos.empty_char = first_line[len_fl - 3];
	// printf("infos_empty_char: %c\n", infos.empty_char);
	infos.nb_lines = ft_atoi(first_line, ft_len(first_line) - 3);
	// printf("infos_nb_lines: %d\n", infos.nb_lines);
	infos.best_size = 0;
	infos.x = 0;
	infos.y = 0;
	infos.matrix = get_new_matrix(matrix);
	// printf("hey infos.matrix\n");
	infos.nb_columns = nb_columns(infos.matrix);
	// printf("infos_nb_col: %d\n", infos.nb_columns);
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
	return (1);
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

void	print_matrix_debug(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
	{
		printf("matrix[%d]: %s\n", i, strs[i]);
		i++;
	}
}

t_plat_info		get_all_infos(char *str)
{
	char		**matrix;
	t_plat_info	infos;

	if (!(matrix = ft_split(str, "\n")))
		infos.matrix = 0;
	// printf("segfault-2\n");
	if (ft_len_strs(matrix) <= 1)
		infos.matrix = 0;
	// printf("segfault-1\n");
	if (!(check_first_line(matrix[0])))
	{
		printf("first line\n");
		infos.matrix = 0;
	}
	// printf("segfault\n");
	infos = assign_el(matrix, matrix[0]);
	if ((check_nb_lines(infos.matrix, infos.nb_lines)) != 0)
	{
		printf("nb_lines\n");
		infos.matrix = 0;
		return (infos);
	}
	// printf("segfault1\n");
	if (!(check_charac(infos.matrix, infos.obstacle, infos.empty_char)))
	{
		printf("check_carac\n");
		infos.matrix = 0;
		return (infos);
	}
	// printf("segfault2\n");
	if (!(check_same_nb_col(infos.matrix)))
	{
		printf("same_col\n");
		infos.matrix = 0;
		return (infos);
	}
	// printf("segfault3\n");
	if ((infos.empty_char == infos.filler) || infos.empty_char == infos.obstacle ||
		 infos.obstacle == infos.filler)
	{
		printf("same charac\n");
		infos.matrix = 0;
		return (infos);
	}
	// print_matrix_debug(infos.matrix);
	// printf("%p\n", &infos);
	// printf("segfault4\n");
	return (infos);
}

t_plat_info		parsing(char *filename)
{
	char			*big_str;
	int				fd;
	int				nb_charac;
	int				ret;
	t_plat_info		infos;

	nb_charac = count_charac(filename);
	if (nb_charac < 4)
	{
		infos.matrix = 0;
		return (infos);
	}
	// printf("ici\n");
	if (!(big_str = malloc(nb_charac)))
	{
		infos.matrix = 0;
		return (infos);
	}
	// printf("ici1\n");
	if ((fd = open(filename, O_RDONLY)) <= 0)
	{
		infos.matrix = 0;
		return (infos);
	}
	// printf("ici2\n");
	if ((ret = read(fd, big_str, nb_charac )) < 1)
	{
		infos.matrix = 0;
		return (infos);
	}	
	// printf("ici3\n");
	big_str[ret] = '\0';
	// printf("ici4\n");
	// printf("big_str:\n%s\n", big_str);
	infos = get_all_infos(big_str);
	// printf("ici5\n");
	return (infos);
}
