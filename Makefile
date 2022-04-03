# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 23:53:36 by ahakam            #+#    #+#              #
#    Updated: 2022/04/03 00:30:51 by ahakam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES =  so_long.c so_long_utils.c so_long_utils_.c  ft_split.c get_data.c get_next_line.c get_next_line_utils.c ft_strchr.c

NAME = so_long

CC = gcc 

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra -g

all : $(NAME) 

$(NAME):
	$(CC)  $(CFLAGS) $(CFILES) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
		
clean : 
			${RM} ${NAME} ${BONUS}
fclean : clean

re : fclean all
