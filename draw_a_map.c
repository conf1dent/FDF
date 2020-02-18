/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_a_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:28:39 by bbekmama          #+#    #+#             */
/*   Updated: 2019/12/05 18:49:35 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	text(t_fdf *head)
{
	mlx_string_put(head->mlx_ptr, head->win_ptr, 10, 10, 0x14a757,
	"Press +/- to zoom/unzoom");
	mlx_string_put(head->mlx_ptr, head->win_ptr, 10, 30, 0xffc300,
	"Press 1/2 to change altitude");
	mlx_string_put(head->mlx_ptr, head->win_ptr, 10, 50, 0xff5733,
	"Press arrow buttons to move");
	mlx_string_put(head->mlx_ptr, head->win_ptr, 10, 70, 0xc70039,
	"Press R/G/O to change colors");
	mlx_string_put(head->mlx_ptr, head->win_ptr, 10, 90, 0x900c3f,
	"Press space to change type of projection");
}

void	draw_a_map(t_fdf *head)
{
	text(head);
	head->y = 0;
	while (head->y < head->height)
	{
		head->x = 0;
		while (head->x < head->width)
		{
			if (head->x < head->width - 1)
			{
				head->x1 = head->x + 1;
				head->y1 = head->y;
				bresenham(*head);
			}
			if (head->y < head->height - 1)
			{
				head->x1 = head->x;
				head->y1 = head->y + 1;
				bresenham(*head);
			}
			head->x += 1;
		}
		head->y += 1;
	}
}
