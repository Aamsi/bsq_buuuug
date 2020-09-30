/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:02:24 by ebedoise          #+#    #+#             */
/*   Updated: 2020/09/30 20:53:49 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_matrix(t_plat_info datas, char **tab, int ac, int index)
{
	int i;

	i = 0;
	while (i < datas.nb_lines)
	{
		ft_str(tab[i]);
		ft_str("\n");
		i++;
	}
	if (index < ac - 1)
		write(1, "\n", 1);
}

char	**fill_square(t_plat_info datas, char **tab, int i)
{
	int j;

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
	tab[i][j] = '\0';
	return (tab);
}

char	**fill_soluce(t_plat_info datas, char **tab)
{
	int i;

	i = 0;
	if (!(tab = malloc(sizeof(char *) * (datas.nb_lines + 1))))
		return (0);
	while (i < datas.nb_lines)
		if (!(tab[i++] = malloc(sizeof(char) * (datas.nb_columns + 1))))
			return (free_split(tab, i));
	i = 0;
	while (i < datas.y)
	{
		tab[i] = datas.matrix[i];
		i++;
	}                                                              
	while (i <= datas.y + datas.best_size)
	{
		tab = fill_square(datas, tab, i);
		i++;
	}
	while (i < datas.nb_lines)
	{
		tab[i] = datas.matrix[i];
		i++;
	}
	tab[i] = 0;
	return (tab);
}
