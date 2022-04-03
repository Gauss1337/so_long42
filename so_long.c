/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:19:14 by ahakam            #+#    #+#             */
/*   Updated: 2022/04/03 00:09:20 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	is_valid_char(char c)
{
	if (c == '0' || c == 'P')
		return (1);
	return (0);
}

void	eat_collectible(int i, int j, t_par *vars)
{
	vars->str[i][j] = '0';
	vars->total_collectibles--;
	if (vars->total_collectibles == 0)
		vars->won = 1;
}

int	is_valid_move_process(int keycode, t_par *vars, int i, int j)
{
	if (ft_strchr("P0CE", vars->str[i + vars->y_player + 1][j + vars->x_player])
		&& (keycode == 125 || keycode == 1))
	{
		if (vars->str[i + vars->y_player + 1][j + vars->x_player] == 'C')
			eat_collectible(i + vars->y_player + 1, j + vars->x_player, vars);
		if (vars->str[i + vars->y_player + 1][j + vars->x_player]
			== 'E' && vars->won)
			exit(1);
		return (1);
	}
	else if (ft_strchr("P0CE", vars->str[i + vars->y_player - 1][j
			+ vars->x_player]) && (keycode == 126 || keycode == 13))
	{
		if (vars->str[i + vars->y_player - 1][j + vars->x_player] == 'C')
			eat_collectible(i + vars->y_player - 1, j + vars->x_player, vars);
		if (vars->str[i + vars->y_player - 1][j
			+ vars->x_player] == 'E' && vars->won)
			exit(1);
		return (1);
	}
	return (0);
}

int	is_valid_up_move(int keycode, t_par *vars, int i, int j)
{
	if (ft_strchr("P0CE", vars->str[i
				+ vars->y_player][j + vars->x_player + 1])
	&& (keycode == 124 || keycode == 2))
	{
		if (vars->str[i + vars->y_player][j
			+ vars->x_player + 1] == 'C')
			eat_collectible(i + vars->y_player, j
				+ vars->x_player + 1, vars);
		if (vars->str[i + vars->y_player][j
			+ vars->x_player + 1] == 'E' && vars->won)
			exit(1);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_par	img;

	argc = 0;
	read_fd(argv[1], &img);
	img.img_height = get_height(argv[1], &img);
	img.mlx = mlx_init();
	img_init(&img);
	mlx_loop(img.mlx);
}
