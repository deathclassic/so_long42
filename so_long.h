/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharmel <tcharmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:41:41 by tcharmel          #+#    #+#             */
/*   Updated: 2021/10/16 22:37:29 by tcharmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"

# define W_KEY	13
# define A_KEY	0
# define S_KEY	1
# define D_KEY	2
# define ESC	53

typedef struct s_list{
	char			*line;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_image{
	void	*img;
	char	*addr;
	int		width;
	int		height;
}	t_image;

typedef struct s_textures{
	t_image	mushroom;
	t_image	grass;
	t_image	bush;
	t_image	chest;
	t_image	exit;
	t_image	coin;
}	t_textures;

typedef struct s_player{
	int	x;
	int	y;
}	t_player;

typedef struct s_config{
	t_textures	textr;
	t_list		*map;
	t_list		*p_pos;
	t_player	player;
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			e_x;
	int			e_y;
	int			pl;
	int			ex;
	int			moves;
	int			coins;
}	t_config;

t_list	*add_list(char *line);
t_list	*get_map(int fd);
t_list	*map_player(t_list *lst);

void	init_config(t_config *config);
void	add_next_element(t_list *start, t_list *nw);
void	init_textures(t_textures *textr);
void	init_img(t_image *img, char *str);
void	ft_macros_2(t_config *config, t_image *img);
void	ft_macros(t_config *config, t_image *img);
void	win_exit(void);

void	check_argv(char *argv, char *str);
void	map_checker(t_list *lst);
void	error_map(void);
void	error_argc(void);
void	error_fd(void);

int		game_exit(void);
int		keypress(int keycode, t_config *config);
int		check_mv(char c, t_config *config);
int		p_index(char *str);

#endif