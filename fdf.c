/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:15:51 by bbekmama          #+#    #+#             */
/*   Updated: 2019/12/05 18:38:09 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_fdf *head)
{
	head->x_shift -= (key == 123) ? 30 : 0;
	head->x_shift += (key == 124) ? 30 : 0;
	head->y_shift += (key == 125) ? 30 : 0;
	head->y_shift -= (key == 126) ? 30 : 0;
	head->zoom -= (key == 27) ? 5 : 0;
	head->zoom += (key == 24) ? 5 : 0;
	head->altitude -= (key == 18) ? 0.3 : 0;
	head->altitude += (key == 19) ? 0.3 : 0;
	if (key == 15)
		head->base_color = 0xff0000;
	if (key == 5)
		head->base_color = 0x007f00;
	if (key == 31)
		head->base_color = 0xffa500;
	if (key == 49)
		head->isom = !head->isom;
	if (key == 53)
		exit(0);
	mlx_clear_window(head->mlx_ptr, head->win_ptr);
	draw_a_map(head);
	return (0);
}

void	init(t_fdf *head)
{
	head->x_shift = 500;
	head->y_shift = 300;
	head->mlx_ptr = mlx_init();
	head->win_ptr = mlx_new_window(head->mlx_ptr, 1000, 1000, "FDF");
	head->zoom = 20;
	head->altitude = 1;
	head->isom = 1;
	head->base_color = 0xff0000;
	head->x = 0;
	head->y = 0;
	head->x1 = 0;
	head->y1 = 0;
}

int		main(int ac, char **av)
{
	t_fdf	*head;

	if (ac != 2)
	{
		write(1, "Too many or few arguments\n", 25);
		return (0);
	}
	head = (t_fdf*)malloc(sizeof(t_fdf));
	read_file(head, av[1]);
	init(head);
	draw_a_map(head);
	mlx_hook(head->win_ptr, 2, 5, deal_key, head);
	mlx_loop(head->mlx_ptr);
	return (0);
}
