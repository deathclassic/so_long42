/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharmel <tcharmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:57:59 by tcharmel          #+#    #+#             */
/*   Updated: 2021/10/16 21:10:56 by tcharmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_macros_2(t_config *config, t_image *img)
{
	img->img = mlx_xpm_file_to_image(config->mlx, img->addr, \
	 &img->width, &img->height);
	mlx_put_image_to_window(config->mlx, config->win, img->img, \
	 config->e_x, config->e_y);
	mlx_destroy_image(config->mlx, img->img);
}

t_list	*get_map(int fd)
{
	t_list	*start;
	char	*line;

	line = NULL;
	start = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (!start)
			start = add_list(ft_strdup(line));
		else
			add_next_element(start, add_list(ft_strdup(line)));
		free(line);
	}
	if (ft_strlen(line) > 0)
		add_next_element(start, add_list(ft_strdup(line)));
	free (line);
	return (start);
}

t_list	*map_player(t_list *lst)
{
	int	i;

	while (lst)
	{
		i = 0;
		while (lst->line[i])
		{
			if (lst->line[i] == 'P')
				return (lst);
			i++;
		}
		lst = lst->next;
	}
	return (NULL);
}

int	p_index(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			return (i);
		i++;
	}
	return (-1);
}

int	check_mv(char c, t_config *config)
{
	if (c == '0' || c == 'C' || (config->coins == 0 && c == 'E'))
		return (1);
	else
		return (0);
}
