/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:44:07 by iouali            #+#    #+#             */
/*   Updated: 2020/09/30 11:49:05 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char		**free_split(char **strs, int j)
{
	while (j >= 0)
	{
		free(strs[j]);
		j--;
	}
	free(strs);
	return (0);
}

int			free_struct(t_plat_info infos)
{
	free(infos.matrix);
	return (0);
}

t_plat_info	reterror(t_plat_info infos, int ertyp, char *big_str, char **matrix)
{
	int i;

	i = 0;
	if (ertyp == 1)
		free(big_str);
	if (ertyp > 1)
	{
		while (matrix[i])
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
		free(big_str);
	}
	infos.matrix = 0;
	return (infos);
}