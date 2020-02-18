/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:29:02 by bbekmama          #+#    #+#             */
/*   Updated: 2019/12/05 18:42:44 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		word_counter(char *row, char c)
{
	int		i;

	i = 0;
	while (*row)
	{
		if (*row != c)
		{
			if (*(row + 1) == c || *(row + 1) == '\0')
				i++;
		}
		row++;
	}
	return (i);
}

int		get_width(char *file)
{
	int		fd;
	char	*line;
	int		width;

	fd = open(file, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = word_counter(line, ' ');
	free(line);
	close(fd);
	return (width);
}

int		get_height(char *file)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = open(file, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	free(line);
	close(fd);
	return (height);
}

void	matrix_filler(int *z_coor, char *line)
{
	int		i;
	char	**numbers;

	i = 0;
	numbers = ft_strsplit(line, ' ');
	while (numbers[i])
	{
		z_coor[i] = ft_atoi(numbers[i]);
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

void	read_file(t_fdf *head, char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	head->height = get_height(file);
	head->width = get_width(file);
	head->z_coor = (int**)malloc(sizeof(int*) * (head->height + 1));
	while (i <= head->height)
		head->z_coor[i++] = (int*)malloc(sizeof(int) * (head->width + 1));
	i = 0;
	fd = open(file, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		matrix_filler(head->z_coor[i], line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
}
