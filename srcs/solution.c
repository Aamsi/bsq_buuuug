/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebedoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:02:24 by ebedoise          #+#    #+#             */
/*   Updated: 2020/09/29 18:21:59 by ebedoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "bsq.h"
#include <libc.h>
typedef struct
{
	int		nb_lines;
	int		nb_columns;
	char	empty_char;
	char	obstacle;
	char	filler;
	char	**matrix;
	int		x;
	int		y;
	int		best_size;
}			t_plat_info;

t_plat_info		solver(t_plat_info datas);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_matrix(t_plat_info datas, char **tab)
{
	int i;

	i = 0;
	while (i < datas.nb_lines)
	{
		ft_putstr(tab[i]);
		ft_putstr("\n");
		i++;
	}
}

char	**fill_soluce(t_plat_info datas, char **tab)
{
	int i;
	int j;

	i = 0;
	if (!(tab = malloc(sizeof(char *) * (datas.nb_lines + 1))))
		return (0);
	while (i < datas.nb_lines)
	{
		if (!(tab[i] = malloc(sizeof(char) * (datas.nb_columns + 1))))
			return (0);
		i++;
	}
	i = 0;
	while (i < datas.y)
	{
		tab[i] = datas.matrix[i];
		i++;
	}
	while (i <= datas.y + datas.best_size)
	{
		j = 0;
		while (j < datas.x)
		{
			tab[i][j] = datas.matrix[i][j];
			j++;
		}
		while (j <= datas.x + datas.best_size)
		{
			tab[i][j] = datas.filler;
			j++;
		}
		while (j < datas.nb_columns)
		{
			tab[i][j] = datas.matrix[i][j];
			j++;
		}
		i++;
	}
	while (i < datas.nb_lines)
	{
		tab[i] = datas.matrix[i];
		i++;
	}
	return (tab);
}

int main()
{
	t_plat_info datas;
	char *str;

	datas.nb_lines = 7;
	datas.nb_columns = 8;
	datas.empty_char = '.';
	datas.obstacle = 'o';
	datas.filler = 'X';
	datas.matrix = malloc(sizeof(char *) * (datas.nb_lines + 1));
	int i = 0;
	while (i < datas.nb_lines)
	{
		datas.matrix[i] = malloc(sizeof(char) * (datas.nb_columns + 1));
		i++;
	}

	str = ".......o";
	datas.matrix[0] = str;
	str = "...o....";
	datas.matrix[1] = str;
	str = ".o..o...";
	datas.matrix[2] = str;
	str = "......o.";
	datas.matrix[3] = str;
	str = "........";
	datas.matrix[4] = str;
	str = ".o..o..o";
	datas.matrix[5] = str;
	str = "........";
	datas.matrix[6] = str;
	datas.matrix[7] = "\0";
	datas.x = 0;
	datas.y = 0;
	datas.best_size = 0;

	print_matrix(datas, datas.matrix);

	datas = solver(datas);
	printf("x = %d\ny = %d\nsize = %d\n", datas.x, datas.y, datas.best_size);

	char **tab = NULL;
	tab = fill_soluce(datas, tab);
	print_matrix(datas, tab);
	return (0);
}
