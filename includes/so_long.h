/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:50:26 by ymehlil           #+#    #+#             */
/*   Updated: 2023/01/25 15:23:57 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <stdlib.h>

typedef struct map
{
	int		column;
	int		line;
	int		items;
	int		p;
	int		exit;
	int		x;
	int		y;
	int		p_x;
	int		p_y;
	int		move;
	int		c_count;
	char	**map;
	void	*mlx;
	void	*win;
	void	*e_img;
	void	*p_img;
	void	*c_img;
	void	*w_img;
	void	*f_img;
}			t_map;

int		main(int ac, char **av, char **env);
int		count_lines(const char *filename);
int		check_map(t_map *data);
int		check_all_lines(t_map *data);
int		ft_strline(char *str);
int		nb_items(t_map *data, char items);
int		check_valid_char(t_map *data);
int		check_first_last_line(t_map *data, int index);
int		check_if_valid_way(t_map *data);
int		ft_change_to_x(t_map *data, int i, int j);
int		valid_way(t_map *data);
int		set_img(t_map *data);
int		handle_input(int keysym, t_map *data);
int		first_check(char **env, int ac, char *s);

void	map_in_struct(t_map *data, char *map);
void	ft_free_all_tab(char **tab, int index);
void	init(t_map *data);
void	display(t_map *data);
void	display_texture(t_map *data, int i, int j);
void	free_mlx(t_map *data);
void	find_p(t_map *data);

void	display_map(t_map *data);

#endif
