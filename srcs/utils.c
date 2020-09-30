/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 10:27:23 by iouali            #+#    #+#             */
/*   Updated: 2020/09/30 10:51:08 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_len_strs(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

int		ft_atoi(char *str, int index)
{
	int i;
	int result;

	result = 0;
	i = 0;
	while (i < index)
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		src_len;
	int		i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	cpy = malloc((1 + src_len) * sizeof(*cpy));
	if (!cpy)
		return (0);
	i = 0;
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
