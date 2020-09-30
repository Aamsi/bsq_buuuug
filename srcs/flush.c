/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:44:07 by iouali            #+#    #+#             */
/*   Updated: 2020/09/30 11:08:36 by iouali           ###   ########.fr       */
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

int		free_struct(t_plat_info infos)
{
	free(infos.matrix);
	return (0);
}