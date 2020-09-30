/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:44:07 by iouali            #+#    #+#             */
/*   Updated: 2020/09/30 21:48:55 by iouali           ###   ########.fr       */
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

t_plat_info	reterror(t_plat_info infos, int ertyp, char *big_str, char **matrix)
{
	int i;

	i = 0;
	ertyp == 1 ? free(big_str) : 0;
	if (ertyp == 2 || ertyp == 3)
	{
		while (matrix[i])
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
		free(big_str);
	}
	i = 0;
	if (ertyp == 3)
	{
		while (infos.matrix[i])
		{
			free(infos.matrix[i]);
			i++;
		}
		free(infos.matrix);
	}
	infos.matrix = 0;
	return (infos);
}

void		free_all_ok(char **strs, char *str)
{
	int i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	free(str);
}

void		free_strs(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}
