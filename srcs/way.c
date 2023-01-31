/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:36:29 by ymehlil           #+#    #+#             */
/*   Updated: 2023/01/27 19:15:43 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	change(t_map *data, int i, int j)
{
	if (data->map[i][j] == 'E')
		data->map[i][j] = '1';
	else
		data->map[i][j] = 'X';
	return (1);
}

int	ft_change_to_x(t_map *data, int i, int j)
{
	int	count;

	count = 0;
	if (data->map[i][j] != 'X')
		count += change(data, i, j);
	if (data->map[i - 1][j] != '1' && data->map[i - 1][j] != 'X')
		count += change(data, i - 1, j);
	if (data->map[i][j - 1] != '1' && data->map[i][j - 1] != 'X')
		count += change(data, i, j - 1);
	if (data->map[i][j + 1] != '1' && data->map[i][j + 1] != 'X')
		count += change(data, i, j + 1);
	if (data->map[i + 1][j] != '1' && data->map[i + 1][j] != 'X')
		count += change(data, i + 1, j);
	return (count);
}

int	check_if_valid_way(t_map *data)
{
	int	e;
	int	i;
	int	p;
	int	c;

	e = nb_items(data, 'E');
	i = nb_items(data, 'I');
	p = nb_items(data, 'P');
	c = nb_items(data, 'C');
	if (e == 0 && i == 0 && p == 0 && c == 0)
		return (1);
	return (0);
}

int	valid_way(t_map *data)
{
	int	i;
	int	j;
	int	count_change;

	count_change = 1;
	while (count_change > 0)
	{
		i = 0;
		count_change = 0;
		while (i < data->line)
		{
			j = 0;
			while (data->map[i][j] && data->map[i][j] != '\n')
			{
				if (data->map[i][j] == 'P' || data->map[i][j] == 'X')
					count_change += ft_change_to_x(data, i, j);
				j++;
			}
			i++;
		}
	}
	return (check_if_valid_way(data));
}
