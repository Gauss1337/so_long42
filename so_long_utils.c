/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 00:02:53 by ahakam            #+#    #+#             */
/*   Updated: 2022/04/03 00:15:38 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	draw_wall(t_par *wall)
{
	int	x;
	int	y;

	y = 0;
	while (y < wall->img_height)
	{
		x = 0;
		while (x < wall->img_width)
		{
			if (wall->str[y][x] == '1')
			{	
				mlx_put_image_to_window(wall->mlx, wall->mlx_win,
					wall->wall, x * 50, y * 50);
			}		
			x++;
		}
		y++;
	}
}

void	draw_map(t_par *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			mlx_put_image_to_window(img->mlx, img->mlx_win,
				img->ground, x * 50, y * 50);
			if (img->str[y][x] == 'C')
				mlx_put_image_to_window(img->mlx, img->mlx_win,
					img->coin, x * 50, y * 50);
			if (img->str[y][x] == 'E')
				mlx_put_image_to_window(img->mlx, img->mlx_win,
					img->door, x * 50, y * 50);
			x++;
		}
		y++;
	}
	draw_wall(img);
	draw_player(img);
}

void	img_init_free(t_par *map)
{
	free(map->data.ground);
	free(map->data.coin);
	free(map->data.wall);
	free(map->data.player);
	free(map->data.portal);
	map->x_player = 0;
	map->y_player = 0;
	map->won = 0;
}

void	img_init(t_par *map)
{
	map->data.ground = ft_strdup("./ground.xpm");
	map->data.coin = ft_strdup("./10dh.xpm");
	map->data.player = ft_strdup("./player.xpm");
	map->data.wall = ft_strdup("./the-wall.xpm");
	map->data.portal = ft_strdup("./door.xpm");
	map->ground = mlx_xpm_file_to_image(map->mlx,
			map->data.ground, &map->width, &map->height);
	map->coin = mlx_xpm_file_to_image(map->mlx,
			map->data.coin, &map->width, &map->height);
	map->player = mlx_xpm_file_to_image(map->mlx,
			map->data.player, &map->width, &map->height);
	map->wall = mlx_xpm_file_to_image(map->mlx,
			map->data.wall, &map->width, &map->height);
	map->door = mlx_xpm_file_to_image(map->mlx,
			map->data.portal, &map->width, &map->height);
	map->mlx_win = mlx_new_window(map->mlx, map->img_width * 50,
			map->img_height * 50, "so_long");
	img_init_free(map);
	draw_map(map);
}

void	draw_player(t_par *player)
{
	int	x;
	int	y;

	y = 0;
	while (y < player->img_height)
	{
		x = 0;
		while (x < player->img_width)
		{
			if (player->str[y][x] == 'P')
				mlx_put_image_to_window(player->mlx,
					player->mlx_win, player->player,
					(player->x_player + x) * 50, (player->y_player + y) * 50);
			mlx_key_hook(player->mlx_win, key_hook, player);
			x++;
		}
		y++;
	}
}
