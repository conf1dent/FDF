
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 20:50:18 by bbekmama          #+#    #+#             */
/*   Updated: 2019/11/08 15:21:23 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define MAX(a, b) (a > b ? a : b)
#define ABS(x) (x < 0 ? -x : x)

void	set_alt_color(t_fdf *head)
{
	head->z *= head->altitude;
	head->z1 *= head->altitude;
	head->color = (head->z || head->z1) ?
	(head->base_color + head->z * 3) : 0xffffff;
}

void	shift_xy(t_fdf *head)
{
	head->x += head->x_shift;
	head->y += head->y_shift;
	head->x1 += head->x_shift;
	head->y1 += head->y_shift;
}

void	zoom_and_view(t_fdf *head)
{
	head->x *= head->zoom;
	head->y *= head->zoom;
	head->x1 *= head->zoom;
	head->y1 *= head->zoom;
	if (head->isom)
		iso(head);
}

void	bresenham(t_fdf head)
{
	float	x_step;
	float	y_step;
	int		maximum;

	head.z = head.z_coor[(int)head.y][(int)head.x];
	head.z1 = head.z_coor[(int)head.y1][(int)head.x1];
	set_alt_color(&head);
	zoom_and_view(&head);
	shift_xy(&head);
	x_step = head.x1 - head.x;
	y_step = head.y1 - head.y;
	maximum = MAX(ABS(x_step), ABS(y_step));
	x_step = x_step / maximum;
	y_step = y_step / maximum;
	while ((int)(head.x - head.x1) || (int)(head.y - head.y1))
	{
		mlx_pixel_put(head.mlx_ptr, head.win_ptr,\
		head.x, head.y, head.color);
		head.x += x_step;
		head.y += y_step;
	}
}
