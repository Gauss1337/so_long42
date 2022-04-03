/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:05:37 by ahakam            #+#    #+#             */
/*   Updated: 2022/04/03 00:30:23 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_str
{
	char	*ground;
	char	*coin;
	char	*player;
	char	*wall;
	char	*portal;
}	t_str;

typedef struct s_par{
	void	*wall;
	int		x_player;
	int		y_player;
	int		x;
	int		y;
	void	*player;
	void	*coin;
	void	*ground;
	void	*door;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		img_width;
	int		img_height;
	int		height;
	int		width;
	char	*matrix;
	char	**str;
	int		total_collectibles;
	int		won;
	t_str	data;
}	t_par;

char	*get_next_line(int fd);
char	**ft_split(char const *str, char c);
int		get_height(char *file_name, t_par *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_atoi(const char *str);
void	draw_map(t_par *img);
void	read_fd(char *fd_name, t_par *data);
char	*ft_strchr(const char *s, int c);
int		is_valid_down_move(int keycode, t_par *vars, int i, int j);
int		is_valid_up_move(int keycode, t_par *vars, int i, int j);
int		key_hook(int keycode, t_par *vars);
int		is_valid_char(char c);
int		is_valid_move(int keycode, t_par *vars);
void	draw_player(t_par *player);
void	click_handle(int keycode, t_par *vars);
void	img_init(t_par *map);
void	img_init_free(t_par *map);
void	draw_wall(t_par *wall);
int		is_valid_move_process(int keycode, t_par *vars, int i, int j);
void	eat_collectible(int i, int j, t_par *vars);

#endif
