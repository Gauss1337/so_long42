/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 00:04:53 by ahakam            #+#    #+#             */
/*   Updated: 2022/04/03 00:15:34 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	key_hook(int keycode, t_par *vars)
{	
	if (keycode == 53)
		exit(0);
	if ((keycode == 124 || keycode == 2) && is_valid_move(keycode, vars))
	{
		vars->x_player += 1;
		mlx_clear_window(vars->mlx, vars->mlx_win);
		draw_map(vars);
	}
	if ((keycode == 1 || keycode == 125) && is_valid_move(keycode, vars))
	{
		vars->y_player += 1;
		mlx_clear_window(vars->mlx, vars->mlx_win);
		draw_map(vars);
	}
	if (keycode == 0 || keycode == 13 || keycode == 123 || keycode == 126)
		click_handle(keycode, vars);
	return (0);
}

int	is_valid_move(int keycode, t_par *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->str[i])
	{
		j = 0;
		while (vars->str[i][j])
		{
			if (vars->str[i][j] == 'P')
			{
				if (((keycode == 123 || keycode == 0)
						&& is_valid_down_move(keycode, vars, i, j))
					|| ((keycode == 124 || keycode == 2)
						&& is_valid_up_move(keycode, vars, i, j)))
					return (1);
				else if ((keycode == 125 || keycode == 1)
					|| (keycode == 126 || keycode == 13))
					return (is_valid_move_process(keycode, vars, i, j));
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	click_handle(int keycode, t_par *vars)
{
	if ((keycode == 0 || keycode == 123) && is_valid_move(keycode, vars))
	{
		vars->x_player -= 1;
		mlx_clear_window(vars->mlx, vars->mlx_win);
		draw_map(vars);
	}
	if ((keycode == 13 || keycode == 126) && is_valid_move(keycode, vars))
	{
		vars->y_player -= 1;
		mlx_clear_window(vars->mlx, vars->mlx_win);
		draw_map(vars);
	}
}

int	is_valid_down_move(int keycode, t_par *vars, int i, int j)
{
	if (ft_strchr("P0CE", vars->str[i
				+ vars->y_player][j + vars->x_player
			- 1]) && (keycode == 123 || keycode == 0))
	{
		if (vars->str[i + vars->y_player][j
			+ vars->x_player - 1] == 'C')
			eat_collectible(i + vars->y_player, j
				+ vars->x_player - 1, vars);
		if (vars->str[i + vars->y_player][j
			+ vars->x_player - 1] == 'E' && vars->won)
			exit(1);
		return (1);
	}
	return (0);
}
