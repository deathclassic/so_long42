/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharmel <tcharmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:56:45 by tcharmel          #+#    #+#             */
/*   Updated: 2021/05/06 18:05:59 by tcharmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	cnt_arr_len(const char *str, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	if (str[i] != 0 && str[i] != c)
		cnt++;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (str[i + 1] != 0 && str[i + 1] != c)
				cnt++;
			i++;
		}
		else
			i++;
	}
	return (cnt);
}

static	char	*ft_strtok(char const *str, char sep, size_t i)
{
	char	*dest;
	size_t	j;
	size_t	z;

	j = i;
	z = 0;
	while (str[i] != sep && str[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i - j + 1));
	if (!dest)
		return (NULL);
	while (j != i)
	{
		dest[z] = str[j];
		j++;
		z++;
	}
	dest[z] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*tmp;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (cnt_arr_len(s, c) + 1));
	if (!arr)
		return (NULL);
	arr[cnt_arr_len(s, c)] = NULL;
	while (i < ft_strlen(s))
	{
		tmp = ft_strtok(s, c, i++);
		if (ft_strlen(tmp) == 0)
			free(tmp);
		else
		{
			arr[j] = tmp;
			i += ft_strlen(arr[j++]);
		}
	}
	return (arr);
}
