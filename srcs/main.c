/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:32:43 by iouali            #+#    #+#             */
/*   Updated: 2020/10/01 10:26:26 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		no_params(int ac)
{
	t_plat_info	datas;
	char		**matrix;

	matrix = 0;
	datas.matrix = 0;
	datas = parsing_stdin();
	if (datas.matrix == 0)
		write(1, "map error\n", 10);
	else
	{
		datas = solver(datas);
		if (datas.x == 0 && datas.y == 0 && datas.best_size == 0 &&
				datas.matrix[0][0] == datas.obstacle)
			print_matrix(datas, datas.matrix, ac, 0);
		else
			print_matrix(datas, fill_soluce(datas, matrix, 0), 0, 0);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_plat_info datas;
	char		**matrix;
	int			i;

	ac == 1 ? no_params(ac) : 0;
	i = 1;
	while (i < ac)
	{
		matrix = 0;
		datas.matrix = 0;
		datas = parsing(av[i]);
		if (datas.matrix == 0)
			i < ac - 1 ? ft_str("map error\n\n") : ft_str("map error\n");
		else
		{
			datas = solver(datas);
			if (datas.x == 0 && datas.y == 0 && datas.best_size == 0 &&
					datas.matrix[0][0] == datas.obstacle)
				print_matrix(datas, datas.matrix, ac, i);
			else
				print_matrix(datas, fill_soluce(datas, matrix, 0), ac, i);
		}
		i++;
	}
	return (0);
}
