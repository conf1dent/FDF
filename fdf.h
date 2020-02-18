/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:16:27 by bbekmama          #+#    #+#             */
/*   Updated: 2019/11/08 14:24:37 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>

typedef struct	s_fdf
{
	int			height;
	int			width;
	int			**z_coor;
	int			zoom;
	int			color;
	int			x_shift;
	int			y_shift;
	int			base_color;
	double		altitude;
	void		*mlx_ptr;
	void		*win_ptr;
	bool		isom;
	float		x;
	float		y;
	float		x1;
	float		y1;
	int			z;
	int			z1;
}				t_fdf;

void			read_file(t_fdf *head, char *file);
void			bresenham(t_fdf head);
void			draw_a_map(t_fdf *head);
void			iso(t_fdf *head);
void			flat(t_fdf *head);
void			update_values(float x, float y, t_fdf *head);
void			update_values2(float x, float y, t_fdf *head);

#endif
