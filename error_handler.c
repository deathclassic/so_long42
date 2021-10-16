/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharmel <tcharmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 21:06:32 by tcharmel          #+#    #+#             */
/*   Updated: 2021/10/16 20:38:32 by tcharmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_argv(char *argv, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
		i++;
	while (str[j])
		j++;
	while (j > 0)
	{
		if (str[j] != argv[i])
		{
			ft_putstr_fd("Error: Invalid map format\n", 2);
			exit(1);
		}
		i--;
		j--;
	}
}

void	error_fd(void)
{
	ft_putstr_fd("Error: invalid file\n", 2);
	exit (1);
}

void	error_argc(void)
{
	ft_putstr_fd("Error: invalid ARGs\n", 2);
	exit (1);
}

void	error_map(void)
{
	ft_putstr_fd("Error: invalid map\n", 2);
	exit(1);
}

void	map_checker(t_list *lst)
{
	int	i;

	while (lst)
	{
		i = 0;
		if (!lst->prev || !lst->next)
		{
			while (lst->line[i])
			{
				if (lst->line[i] != '1')
					error_map();
				i++;
			}
		}
		if (lst->line[0] != '1' || lst->line[ft_strlen(lst->line) - 1] != '1')
			error_map();
		lst = lst->next;
	}
}
