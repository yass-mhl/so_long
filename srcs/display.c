/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:13:00 by ymehlil           #+#    #+#             */
/*   Updated: 2023/01/27 15:26:14 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_texture(t_map *data, int i, int j)
{
	if (data->map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->p_img, data->x,
			data->y);
	else if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->w_img, data->x,
			data->y);
	else if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->f_img, data->x,
			data->y);
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->c_img, data->x,
			data->y);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->e_img, data->x,
			data->y);
}

void	display(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	data->y = 0;
	while (i < data->line)
	{
		j = 0;
		data->x = 0;
		while (j < data->column)
		{
			display_texture(data, i, j);
			j++;
			data->x += 64;
		}
		i++;
		data->y += 64;
	}
}

int	set_img(t_map *data)
{
	int	i;

	data->f_img = mlx_xpm_file_to_image(data->mlx, "./img/f.xpm", &i, &i);
	if (!data->f_img)
		return (0);
	data->w_img = mlx_xpm_file_to_image(data->mlx, "./img/w.xpm", &i, &i);
	if (!data->w_img)
		return (0);
	data->c_img = mlx_xpm_file_to_image(data->mlx, "./img/c.xpm", &i, &i);
	if (!data->c_img)
		return (0);
	data->p_img = mlx_xpm_file_to_image(data->mlx, "./img/p.xpm", &i, &i);
	if (!data->p_img)
		return (0);
	data->e_img = mlx_xpm_file_to_image(data->mlx, "./img/e.xpm", &i, &i);
	if (!data->e_img)
		return (0);
	return (1);
}

void	init(t_map *data)
{
	int	i;

	data->win = mlx_new_window(data->mlx, data->column * 64, data->line * 64,
			"So Long");
	if (!data->win)
	{
		free(data->mlx);
		ft_free_all_tab(data->map, data->line);
		exit(0);
	}
	i = set_img(data);
	if (!i)
	{
		free_mlx(data);
		ft_free_all_tab(data->map, data->line);
		exit(0);
	}
	display(data);
	mlx_key_hook(data->win, &handle_input, data);
	mlx_hook(data->win, 17, 1L << 17, mlx_loop_end, data->mlx);
	mlx_loop(data->mlx);
}
