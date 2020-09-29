/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebedoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 10:03:01 by ebedoise          #+#    #+#             */
/*   Updated: 2020/09/29 18:21:57 by ebedoise         ###   ########.fr       */
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

typedef struct	s_tester
{
	int			x;
	int			y;
	int			x_bis;
	int			y_bis;
}				t_tester;

int			first_column_tester(t_plat_info datas, t_tester test)
{
	int i;
	int j;

	i = test.y;
	j = test.x;
	if (test.y_bis == datas.nb_lines)
		return (0);
	while (i <= test.y_bis)
	{
		if (datas.matrix[i][j] == datas.obstacle)
			return (0);
		i++;
	}
	return (1);
}

int		second_column_tester(t_plat_info datas, t_tester test)
{
	int i;
	int j;

	i = test.y;
	j = test.x_bis;
	while (i <= test.y_bis)
	{
		if (datas.matrix[i][j] == datas.obstacle)
			return (0);
		i++;
	}
	return (1);
}


int			first_line_tester(t_plat_info datas, t_tester test)
{
	int i;
	int j;

	i = test.y;
	j = test.x;
	while (j <= test.x_bis)
	{
		if (datas.matrix[i][j] == datas.obstacle)
			return (0);
		j++;
	}
	return (1);
}

int			second_line_tester(t_plat_info datas, t_tester test)
{
	int i;
	int j;

	i = test.y_bis;
	j = test.x;
	while (j <= test.x_bis)
	{
		if (datas.matrix[i][j] == datas.obstacle)
			return (0);
		j++;
	}
	return (1);
}

t_plat_info	turbo_tester(t_plat_info datas, int i, int j)
{
	t_tester	test;

	test.x = j;
	test.y = i;
	test.x_bis = j;
	test.y_bis = i;
	while (first_column_tester(datas, test) && first_line_tester(datas, test)
			&& second_column_tester(datas, test) && second_line_tester(datas, test)
			&& test.x_bis < datas.nb_columns && test.y_bis < datas.nb_lines)
	{
		if (test.x_bis - test.x > datas.best_size)
		{
			datas.x = test.x;
			datas.y = test.y;
			datas.best_size = test.x_bis - test.x;
		}
		test.x_bis++;
		test.y_bis++;
	}
	return (datas);
}

t_plat_info	solver(t_plat_info datas)
{
	int	i;
	int j;

	i = 0;
	while (i < datas.nb_lines)
	{
		j = 0;
		while (j < datas.nb_columns)
		{
			if (datas.matrix[i][j] == datas.obstacle)
				j++;
			else
			{
				datas = turbo_tester(datas, i, j);
				j++;
			}
		}
		i++;
	}
	return (datas);
}
