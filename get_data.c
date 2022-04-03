/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:08:01 by ahakam            #+#    #+#             */
/*   Updated: 2022/04/03 00:26:36 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*btr;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	btr = str;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}

int	get_height(char *file_name, t_par *s)
{
	int		i;
	int		fd;
	char	*ptr;

	fd = open(file_name, O_RDONLY);
	i = 0;
	ptr = get_next_line(fd);
	if (ptr)
		s->img_width = ft_strlen(ptr) - 1;
	while (ptr != NULL)
	{
		i++;
		free(ptr);
		ptr = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	fd_error(int fd)
{
	if (fd == -1)
	{
		perror("file not found!\n");
		exit(1);
	}
}

void	read_fd(char *fd_name, t_par *data)
{
	int		fd;
	char	*line;
	char	*tmp;
	int		i;

	fd = open(fd_name, O_RDONLY);
	fd_error(fd);
	data->total_collectibles = 0;
	data->matrix = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i])
			if (line[i++] == 'C')
				data->total_collectibles++;
		tmp = data->matrix;
		data->matrix = ft_strjoin(data->matrix, line);
		free(line);
		line = get_next_line(fd);
		free(tmp);
	}
	data->str = ft_split(data->matrix, '\n');
	close(fd);
}
