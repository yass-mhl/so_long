/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:42:15 by ymehlil           #+#    #+#             */
/*   Updated: 2023/01/27 19:37:49 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	first_check(char **env, int ac, char *s)
{
	if (!env || !(*env) || env[0][0] == '\0')
	{
		ft_putstr_fd("Error\n: env not found", 1);
		return (0);
	}
	if (ac > 2)
	{
		ft_putstr_fd("Error\n: too much arg", 1);
		return (0);
	}
	if (ac < 2)
	{
		ft_putstr_fd("Error\n: not enough arg", 1);
		return (0);
	}
	if (s[ft_strlen(s) - 1] != 'r' || s[ft_strlen(s) - 2] != 'e' || \
		s[ft_strlen(s) - 3] != 'b' || s[ft_strlen(s) - 4] != '.')
	{
		ft_putstr_fd("Error\n: not in .ber", 1);
		return (0);
	}
	return (1);
}

void	init_data(t_map *data)
{
	data->line = 0;
	data->column = 0;
	data->move = 0;
	data->c_count = 0;
	data->map = NULL;
	data->mlx = NULL;
	data->win = NULL;
	data->f_img = NULL;
	data->w_img = NULL;
	data->c_img = NULL;
	data->p_img = NULL;
	data->e_img = NULL;
}

int	main(int ac, char **av, char **env)
{
	t_map	data;

	if (!first_check(env, ac, av[1]))
		return (0);
	init_data(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (ft_printf("Error\n: env not found", 0));
	map_in_struct(&data, av[1]);
	if (!data.map)
		return (ft_printf("Error\n: Map is invalid"), free_mlx(&data), 0);
	if (!check_map(&data) || !valid_way(&data) || data.map[0][0] == 0)
	{
		ft_free_all_tab(data.map, data.line);
		mlx_destroy_display(data.mlx);
		ft_putstr_fd("Error\n: map is invalid\n", 1);
		return (free(data.mlx), 0);
	}
	ft_free_all_tab(data.map, data.line);
	if (map_in_struct(&data, av[1]))
		return (free(data.mlx), 0);
	init(&data);
	free_mlx(&data);
	ft_free_all_tab(data.map, data.line);
}
