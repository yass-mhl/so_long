/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:09:17 by ymehlil           #+#    #+#             */
/*   Updated: 2023/01/27 18:22:47 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_data(t_map *data)
{
	data->column = ft_strline(data->map[0]);
	data->items = nb_items(data, 'C');
	data->exit = nb_items(data, 'E');
	data->p = nb_items(data, 'P');
}

int	map_in_struct(t_map *data, char *map)
{
	int		fd;
	int		i;
	int		nb_line;
	char	**all_lines;

	i = -1;
	nb_line = count_lines(map);
	if (nb_line < 0 || nb_line == 0)
		return (1);
	data->line = nb_line;
	all_lines = malloc(sizeof(char *) * (nb_line + 1));
	if (!all_lines)
		return (1);
	fd = open(map, O_RDONLY);
	if (fd <= 0)
		return (ft_free_all_tab(all_lines, nb_line), 1);
	while (++i < nb_line)
	{
		all_lines[i] = get_next_line(fd);
		if (!all_lines[i])
			return (ft_free_all_tab(all_lines, i), 1);
	}
	all_lines[i] = 0;
	data->map = all_lines;
	return (fill_data(data), close(fd), 0);
}
