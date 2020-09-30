/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 09:32:58 by iouali            #+#    #+#             */
/*   Updated: 2020/09/30 14:52:25 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_is_sep(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_nb_words(char *str, char *charset)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!ft_is_sep(str[i], charset))
		{
			j++;
			while (str[i] && !ft_is_sep(str[i], charset))
				i++;
		}
		else
			i++;
	}
	return (j);
}

int		ft_lsep(int n, char *str, char *charset)
{
	int i;
	int j;

	i = n;
	j = 0;
	while (str[i] && !ft_is_sep(str[i], charset))
	{
		j++;
		i++;
	}
	return (j);
}

char	**ft_split(char *str, char *sep)
{
	char	**array;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!(array = malloc(sizeof(char *) * (ft_nb_words(str, sep) + 1))))
		return (0);
	while (str[i])
	{
		k = 0;
		if (!ft_is_sep(str[i], sep))
		{
			if (!(array[j] = malloc(sizeof(char) * (ft_lsep(i, str, sep) + 1))))
				return (free_split(array, j));
			while (!ft_is_sep(str[i], sep) && str[i])
				array[j][k++] = str[i++];
			array[j++][k] = '\0';
		}
		else
			i++;
	}
	array[j] = 0;
	return (array);
}

char	**get_new_matrix(char **strs)
{
	int		i;
	int		len_matrix;
	char	**new_matrix;

	len_matrix = 1;
	while (strs[len_matrix])
		len_matrix++;
	if (!(new_matrix = malloc(sizeof(new_matrix) * len_matrix)))
		return (0);
	i = 1;
	while (strs[i])
	{
		if (!(new_matrix[i - 1] = ft_strdup(strs[i])))
			return (free_split(new_matrix, i - 1));
		i++;
	}
	new_matrix[i - 1] = 0;
	return (new_matrix);
}
