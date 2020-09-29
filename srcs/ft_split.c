/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 09:32:58 by iouali            #+#    #+#             */
/*   Updated: 2020/09/29 09:33:34 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		ft_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

	strs = malloc(sizeof(strs) * (count_words(str, charset) + 1));
	i = 0;
	j = 0;
	while (is_sep(str[i], charset))
		i++;
	while (str[i])
	{
		if (!is_sep(str[i], charset))
		{
			k = -1;
			strs[j] = malloc(sizeof(*strs) * (count_let(str, charset, i) + 1));
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
