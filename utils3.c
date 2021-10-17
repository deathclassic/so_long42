/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharmel <tcharmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:53:54 by tcharmel          #+#    #+#             */
/*   Updated: 2021/10/17 16:29:39 by tcharmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_config(t_config *config)
{
	config->mlx = mlx_init();
	config->map = NULL;
	config->moves = 0;
	config->coins = 0;
	config->pl = 0;
	config->ex = 0;
	config->lr = 0;
}

int	game_exit(void)
{
	ft_putstr_fd("Exit\n", 1);
	exit(0);
}

void	win_exit(void)
{
	ft_putstr_fd("Congratulations, You Won! :D\n", 1);
	exit (0);
}

void	check_rectangle(t_list *lst)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (lst->line[i])
		i++;
	j = i;
	tmp = j;
	lst = lst->next;
	while (lst)
	{
		i = 0;
		while (lst->line[i])
			i++;
		j = i;
		if (tmp != j)
			error_map();
		lst = lst->next;
	}
}
