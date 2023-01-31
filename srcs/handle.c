/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:39:18 by ymehlil           #+#    #+#             */
/*   Updated: 2023/01/25 15:14:52 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move_up(t_map *data)
{
	int		i;
	int		j;
	char	c;

	find_p(data);
	i = data->p_y;
	j = data->p_x;
	c = data->map[i - 1][j];
	if ((c != '1' && c != 'E') || (c == 'E' && data->c_count == data->items))
	{
		if (data->map[i - 1][j] == 'C')
			data->c_count++;
		if (data->map[i - 1][j] == 'E')
			mlx_loop_end(data->mlx);
		data->map[i][j] = '0';
		data->map[i - 1][j] = 'P';
		data->move++;
		ft_printf("Moves : %d\n", data->move);
		display(data);
		return (1);
	}
	return (0);
}

int	move_right(t_map *data)
{
	int		i;
	int		j;
	char	c;

	find_p(data);
	i = data->p_y;
	j = data->p_x;
	c = data->map[i][j + 1];
	if ((c != '1' && c != 'E') || (c == 'E' && data->c_count == data->items))
	{
		if (data->map[i][j + 1] == 'C')
			data->c_count++;
		if (data->map[i][j + 1] == 'E')
			mlx_loop_end(data->mlx);
		data->map[i][j] = '0';
		data->map[i][j + 1] = 'P';
		data->move++;
		ft_printf("Moves : %d\n", data->move);
		display(data);
		return (1);
	}
	return (0);
}

int	move_down(t_map *data)
{
	int		i;
	int		j;
	char	c;

	find_p(data);
	i = data->p_y;
	j = data->p_x;
	c = data->map[i + 1][j];
	if ((c != '1' && c != 'E') || (c == 'E' && data->c_count == data->items))
	{
		if (data->map[i + 1][j] == 'C')
			data->c_count++;
		if (data->map[i + 1][j] == 'E')
			mlx_loop_end(data->mlx);
		data->map[i][j] = '0';
		data->map[i + 1][j] = 'P';
		data->move++;
		ft_printf("Moves : %d\n", data->move);
		display(data);
		return (1);
	}
	return (0);
}

int	move_left(t_map *data)
{
	int		i;
	int		j;
	char	c;

	find_p(data);
	i = data->p_y;
	j = data->p_x;
	c = data->map[i][j - 1];
	if ((c != '1' && c != 'E') || (c == 'E' && data->c_count == data->items))
	{
		if (data->map[i][j - 1] == 'C')
			data->c_count++;
		if (data->map[i][j - 1] == 'E')
			mlx_loop_end(data->mlx);
		data->map[i][j] = '0';
		data->map[i][j - 1] = 'P';
		data->move++;
		ft_printf("Moves : %d\n", data->move);
		display(data);
		return (1);
	}
	return (0);
}

int	handle_input(int keysym, t_map *data)
{
	if (keysym == XK_Escape)
		mlx_loop_end(data->mlx);
	else if (keysym == 119)
		move_up(data);
	else if (keysym == 100)
		move_right(data);
	else if (keysym == 115)
		move_down(data);
	else if (keysym == 97)
		move_left(data);
	return (0);
}
