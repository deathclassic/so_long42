/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharmel <tcharmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 21:58:41 by tcharmel          #+#    #+#             */
/*   Updated: 2021/05/06 18:26:30 by tcharmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	void	*str;

	len = ft_strlen(s1) + 1;
	str = (char *)malloc(len);
	if (str == 0)
		return (NULL);
	return ((char *)ft_memcpy(str, s1, len));
}
