/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 09:07:48 by iouali            #+#    #+#             */
/*   Updated: 2020/09/29 09:40:23 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		count_charac(char *file_name)
{
	int		fd;
	char	buf[1];
	int		nb_charac;

	nb_charac = 0;
	if ((fd = open(file_name, O_RDONLY)) <= 0)
		return (0);
	while (read(fd, buf, 1) > 0)
		nb_charac++;
	close(fd);
	return (nb_charac);
}

int		check_first_line(char *str)
{
	
}

char **get_matrix(char *str)
{
	char	*big_str;

	big_str = ft_split(str, "\n");

}