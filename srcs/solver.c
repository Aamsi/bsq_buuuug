/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebedoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 10:03:01 by ebedoise          #+#    #+#             */
/*   Updated: 2020/09/29 11:59:50 by ebedoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

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

int			second_line_tester(t_plat_info, t_tester test)
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
	test.x_bis = j + 1;
	test.y_bis = i + 1;
	while (column_tester(datas, test) && line_tester(datas, test)
			&& )
	{
		if (test.x - test.x_bis > datas.best_size)
		{
			datas.x = test.x;
			datas.y = test.y;
			datas.best_size = test.x - test.x_bis;
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
		while (j < datas.nb_lines)
		{
			if (datas.matrix[i][j] == datas.obstacle)
				j++;
			else
			{
				turbo_tester(datas, i, j);
				j++;
			}
		}
		i++;
	}
	return (datas);
}
