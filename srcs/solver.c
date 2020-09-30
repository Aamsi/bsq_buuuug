/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 10:03:01 by ebedoise          #+#    #+#             */
/*   Updated: 2020/09/30 13:42:37 by ebedoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_plat_info		solver(t_plat_info datas)
{
	int	i;
	int j;

	i = 0;
	while (i < datas.nb_lines - datas.best_size)
	{
		j = 0;
		while (j < datas.nb_columns - datas.best_size)
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
