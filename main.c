/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharmel <tcharmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:38:16 by tcharmel          #+#    #+#             */
/*   Updated: 2021/10/16 22:09:18 by tcharmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_resolution(t_list *lst, t_config *config)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (lst)
	{
		while (lst->line[i])
		{
			x++;
			i++;
		}
		y++;
		lst = lst->next;
	}
	x *= 32;
	y *= 32;
	config->win = mlx_new_window(config->mlx, x, y, "so_long");
}

void	put_image_add(char c, t_config *config)
{
	if (c == 'E')
	{
		ft_macros(config, &(config->textr.chest));
		config->e_x = config->x;
		config->e_y = config->y;
		config->ex++;
	}
	else if (c == 'P')
	{
		ft_macros(config, &(config->textr.mushroom));
		config->player.x = config->x;
		config->player.y = config->y;
		config->pl++;
	}
}

void	put_image(char c, t_config *config)
{
	ft_macros(config, &(config->textr.grass));
	if (c == '1')
		ft_macros(config, &(config->textr.bush));
	else if (c == 'C')
	{
		ft_macros(config, &(config->textr.coin));
		config->coins++;
	}
	else if (c == 'E' || c == 'P')
		put_image_add(c, config);
	else if (c == '0')
		return ;
	else
		error_map();
}

void	put_pictures(t_list *lst, t_config *config)
{
	int	i;

	config->y = 0;
	config->x = 0;
	while (lst)
	{
		i = 0;
		config->x = 0;
		while (lst->line[i])
		{
			put_image(lst->line[i], config);
			config->x += 32;
			i++;
		}
		lst = lst->next;
		config->y += 32;
	}
	config->x = config->player.x;
	config->y = config->player.y;
}

int	main(int argc, char **argv)
{
	t_config	config;
	int			fd;

	if (argc != 2)
		error_argc();
	init_config(&config);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_fd();
	check_argv(argv[1], ".ber");
	config.map = get_map(fd);
	map_checker(config.map);
	init_textures(&(config.textr));
	get_resolution(config.map, &config);
	put_pictures(config.map, &config);
	if (config.ex == 0 || config.pl == 0 || config.ex > 1 || config.pl > 1)
		error_map();
	config.p_pos = map_player(config.map);
	mlx_hook(config.win, 2, 1L << 0, keypress, &config);
	mlx_hook(config.win, 17, 0, &game_exit, &config);
	mlx_loop(config.mlx);
	return (0);
}
