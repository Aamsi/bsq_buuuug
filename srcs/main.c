/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:32:43 by iouali            #+#    #+#             */
/*   Updated: 2020/09/30 11:49:27 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		main(int ac, char **av)
{
	t_plat_info datas;
	char		**matrix;

	(void)ac;
	matrix = 0;
	datas = parsing(av[1]);
	if (datas.matrix == 0)
	{
		write(1, "map error\n", 10);
		return (0);
	}
	datas = solver(datas);
	if (datas.x == 0 && datas.y == 0 && datas.best_size == 0 &&
		datas.matrix[0][0] == datas.obstacle)
	{
		write(1, "map error\n", 10);
		return (0);
	}
	matrix = fill_soluce(datas, matrix);
	print_matrix(datas, matrix);
	return (0);
}
