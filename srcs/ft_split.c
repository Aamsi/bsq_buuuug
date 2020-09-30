/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 09:32:58 by iouali            #+#    #+#             */
/*   Updated: 2020/09/30 10:52:13 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		is_sep(char c, char *charset)
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

int		count_words(char *str, char *charset)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (is_sep(str[i], charset))
		i++;
	i++;
	while (str[i])
	{
		if (is_sep(str[i - 1], charset) && !is_sep(str[i], charset))
			count++;
		i++;
	}
	return (count + 1);
}

int		count_let(char *str, char *charset, int index)
{
	int j;

	j = index;
	while (!is_sep(str[index], charset) && str[index])
		index++;
	return (index - j);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		i;
	int		j;
	int		k;

	if (!(strs = malloc(sizeof(strs) * (count_words(str, charset) + 1))))
		return (0);
	i = 0;
	j = 0;
	while (is_sep(str[i], charset))
		i++;
	while (str[i])
	{
		if (!is_sep(str[i], charset))
		{
			k = -1;
			if (!(strs[j] = malloc(sizeof(*strs) * (count_let(str, charset, i) + 1))))
				return (free_split(strs, j));
			while (!is_sep(str[i], charset) && str[i])
				strs[j][++k] = str[i++];
			strs[j][++k] = '\0';
			j++;
		}
		i++;
	}
	strs[j] = 0;
	return (strs);
}

char	**get_new_matrix(char **strs)
{
	int i;
	int	len_matrix;
	char **new_matrix;

	len_matrix = 1;
	while (strs[len_matrix])
		len_matrix++;
	if (!(new_matrix = malloc(sizeof(new_matrix) * len_matrix)))
		return (0);
	i = 1;
	while (strs[i])
	{
		if (!(new_matrix[i - 1]= ft_strdup(strs[i])))
			return (free_split(new_matrix, i - 1));
		i++;
	}
	new_matrix[i - 1] = 0;
	return (new_matrix);
}