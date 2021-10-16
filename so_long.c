/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharmel <tcharmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:44:03 by tcharmel          #+#    #+#             */
/*   Updated: 2021/10/16 21:11:33 by tcharmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_pos_x(t_config *config, int keycode, int i)
{
	ft_macros(config, &(config->textr.grass));
	if (keycode == A_KEY)
	{
		config->x -= 32;
		config->p_pos->line[i] = '0';
		if (config->p_pos->line[i - 1] == 'C')
			config->coins--;
		else if (config->p_pos->line[i - 1] == 'E')
			win_exit();
		config->p_pos->line[i - 1] = 'P';
	}
	else if (keycode == D_KEY)
	{
		config->x += 32;
		config->p_pos->line[i] = '0';
		if (config->p_pos->line[i + 1] == 'C')
			config->coins--;
		else if (config->p_pos->line[i + 1] == 'E')
			win_exit();
		config->p_pos->line[i + 1] = 'P';
	}
	ft_macros(config, &(config->textr.mushroom));
	printf("moves: %d\n", ++config->moves);
}

void	get_pos_y(t_config *config, int keycode, int i)
{
	ft_macros(config, &(config->textr.grass));
	if (keycode == W_KEY)
	{
		config->y -= 32;
		config->p_pos->line[i] = '0';
		config->p_pos = config->p_pos->prev;
		if (config->p_pos->line[i] == 'C')
			config->coins--;
		else if (config->p_pos->line[i] == 'E')
			win_exit();
		config->p_pos->line[i] = 'P';
	}
	else if (keycode == S_KEY)
	{
		config->y += 32;
		config->p_pos->line[i] = '0';
		config->p_pos = config->p_pos->next;
		if (config->p_pos->line[i] == 'C')
			config->coins--;
		else if (config->p_pos->line[i] == 'E')
			win_exit();
		config->p_pos->line[i] = 'P';
	}
	ft_macros(config, &(config->textr.mushroom));
	printf("moves: %d\n", ++config->moves);
}

void	move_player(t_config *config, int keycode)
{
	int		i;

	i = p_index(config->p_pos->line);
	if (keycode == W_KEY && check_mv(config->p_pos->prev->line[i], config))
		get_pos_y(config, keycode, i);
	else if (keycode == S_KEY && check_mv(config->p_pos->next->line[i], config))
		get_pos_y(config, keycode, i);
	else if (keycode == A_KEY && check_mv(config->p_pos->line[i - 1], config))
		get_pos_x(config, keycode, i);
	else if (keycode == D_KEY && check_mv(config->p_pos->line[i + 1], config))
		get_pos_x(config, keycode, i);
	if (config->coins == 0)
	{
		ft_macros_2(config, &(config->textr.grass));
		ft_macros_2(config, &(config->textr.exit));
	}
}

int	keypress(int keycode, t_config *config)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(config->mlx, config->win);
		ft_putstr_fd("exit\n", 1);
		exit(0);
	}
	if (keycode == W_KEY || keycode == A_KEY \
	 || keycode == S_KEY || keycode == D_KEY)
		move_player(config, keycode);
	return (0);
}
