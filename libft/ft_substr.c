/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharmel <tcharmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 19:41:55 by tcharmel          #+#    #+#             */
/*   Updated: 2021/05/06 18:05:51 by tcharmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	l;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int) ft_strlen(s))
		return (ft_strdup(""));
	l = ft_strlen(s) - start + 1;
	if (l <= len)
		str = (char *)malloc(sizeof(char) * (l + 1));
	if (l > len)
	{
		l = len;
		str = (char *)malloc(sizeof(char) * (len + 1));
	}
	if (!str)
		return (NULL);
	while (i < l)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}
