/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharmel <tcharmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:50:10 by tcharmel          #+#    #+#             */
/*   Updated: 2021/10/17 16:00:07 by tcharmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_macros(t_config *config, t_image *img)
{
	img->img = mlx_xpm_file_to_image(config->mlx, img->addr, \
	 &img->width, &img->height);
	mlx_put_image_to_window(config->mlx, config->win, img->img, \
	 config->x, config->y);
	mlx_destroy_image(config->mlx, img->img);
}

void	init_img(t_image *img, char *str)
{
	img->addr = str;
	img->height = 32;
	img->width = 32;
}

void	init_textures(t_textures *textr)
{
	init_img(&(textr->grass), "./textures/grass.xpm");
	init_img(&(textr->mushroom), "./textures/mushroom.xpm");
	init_img(&(textr->coin), "./textures/coin.xpm");
	init_img(&(textr->chest), "./textures/chest.xpm");
	init_img(&(textr->bush), "./textures/bush.xpm");
	init_img(&(textr->exit), "./textures/chest_open.xpm");
	init_img(&(textr->mushroom2), "./textures/mushroom2.xpm");
}

t_list	*add_list(char *line)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->line = line;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	add_next_element(t_list *start, t_list *nw)
{
	t_list	*ptr;

	ptr = start;
	if (ptr->next)
		while (ptr->next)
			ptr = ptr->next;
	ptr->next = nw;
	nw->prev = ptr;
}
