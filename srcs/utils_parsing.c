/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 11:37:53 by iouali            #+#    #+#             */
/*   Updated: 2020/09/30 14:54:46 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		count_charac(char *filename)
{
	int		fd;
	char	buf[1];
	int		nb_charac;
	int		ret;

	nb_charac = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);
	while ((ret = read(fd, buf, 1) > 0))
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
		i++;
	}
	return (1);
}

int		nb_columns(char **matrix)
{
	int i;

	i = 0;
	if (!matrix[0])
		return (i);
	while (matrix[0][i])
		i++;
	return (i);
}

int		check_nb_lines(char **matrix, int nb_lines)
{
	int i;

	i = 0;
	while (matrix[i])
		i++;
	return (i - nb_lines);
}

int		check_charac(char **matrix, char obst, char empty)
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
