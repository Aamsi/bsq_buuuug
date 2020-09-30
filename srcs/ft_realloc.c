/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 14:53:40 by iouali            #+#    #+#             */
/*   Updated: 2020/09/30 14:54:25 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_realloc(char *ptr, int size)
{
	char	*tmp;
	int		i;

	if (!(tmp = malloc(sizeof(char) * size)))
		return (0);
	i = 0;
	while (ptr[i])
	{
		tmp[i] = ptr[i];
		i++;
	}
	tmp[i] = '\0';
	free(ptr);
	return (tmp);
}
