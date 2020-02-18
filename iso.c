/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 13:23:20 by bbekmama          #+#    #+#             */
/*   Updated: 2019/11/08 15:04:48 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(t_fdf *head)
{
	head->x = (head->x - head->y) * cos(0.8);
	head->y = (head->x + head->y) * sin(0.8) - head->z;
	head->x1 = (head->x1 - head->y1) * cos(0.8);
	head->y1 = (head->x1 + head->y1) * sin(0.8) - head->z1;
}
