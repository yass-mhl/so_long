/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:51:54 by ymehlil           #+#    #+#             */
/*   Updated: 2023/01/27 19:33:56 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

int	check_first_last_line(t_map *data, int index)
{
	int	i;

	i = 0;
	while (data->map[index][i] && data->map[index][i] != '\n')
	{
		if (data->map[index][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_all_lines(t_map *data)
{
	int	i;

	if (data->column < 3)
		return (0);
	if (!check_first_last_line(data, 0))
		return (0);
	if (!check_first_last_line(data, data->line - 1))
		return (0);
	i = 0;
	while (i < data->line)
	{
		if (data->column != ft_strline(data->map[i]))
		{
			return (0);
		}
		if (data->map[i][0] != '1' || data->map[i][data->column - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	nb_items(t_map *data, char items)
{
	int	i;
	int	j;
	int	count_items;

	i = 0;
	count_items = 0;
	while (i < data->line)
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
		{
			if (data->map[i][j] == items)
				count_items++;
			j++;
		}
		i++;
	}
	return (count_items);
}

int	check_valid_char(t_map *data)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < data->line)
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
		{
			c = data->map[i][j];
			if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map(t_map *data)
{
	if (data->line < 3)
		return (0);
	if (data->column < 3)
		return (0);
	if (!check_all_lines(data) || data->items < 1 || data->p != 1)
		return (0);
	if (data->exit != 1)
		return (0);
	if (!check_valid_char(data))
		return (0);
	return (1);
}
