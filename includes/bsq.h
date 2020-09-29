/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouali <iouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 09:21:44 by iouali            #+#    #+#             */
/*   Updated: 2020/09/29 09:35:26 by iouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct	s_plat_info
{
	int		nb_lines;
	char	empty_car;
	char	obstacle;
	char	filler;
	char	**matrix;
}				t_plat_info;

#endif
