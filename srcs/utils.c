/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:31:09 by ymehlil           #+#    #+#             */
/*   Updated: 2023/01/27 19:35:49 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_p(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->line)
	{
		j = 0;
		while (j < data->column)
		{
			if (data->map[i][j] == 'P')
			{
				data->p_x = j;
				data->p_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_free_all_tab(char **tab, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_strline(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	count_lines(const char *filename)
{
	char	c;
	int		fd;
	int		line_count;
	int		bytes_read;

	line_count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	bytes_read = read(fd, &c, 1);
	while (bytes_read > 0)
	{
		if (c == '\n')
		{
			line_count++;
		}
		bytes_read = read(fd, &c, 1);
	}
	close(fd);
	return (line_count);
}

void	free_mlx(t_map *data)
{
	if (data->e_img)
		mlx_destroy_image(data->mlx, data->e_img);
	if (data->p_img)
		mlx_destroy_image(data->mlx, data->p_img);
	if (data->c_img)
		mlx_destroy_image(data->mlx, data->c_img);
	if (data->w_img)
		mlx_destroy_image(data->mlx, data->w_img);
	if (data->f_img)
		mlx_destroy_image(data->mlx, data->f_img);
	if (data->win)
	{
		mlx_clear_window(data->mlx, data->win);
		mlx_destroy_window(data->mlx, data->win);
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}
