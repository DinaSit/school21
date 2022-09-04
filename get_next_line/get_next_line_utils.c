/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoyama <rkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:53:30 by rkoyama           #+#    #+#             */
/*   Updated: 2021/11/28 00:20:29 by rkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*str1;

	str1 = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!str1)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str1[i] = str[i];
		++i;
	}
	str1[i] = 0;
	return ((char *)str1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str1;

	if (!s1 || !s2)
		return (NULL);
	str1 = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	if (!str1)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str1[i] = s1[i];
		++i;
	}
	while (s2[i - ft_strlen((char *)s1)])
	{
		str1[i] = s2[i - ft_strlen((char *)s1)];
		++i;
	}
	str1[i] = '\0';
	return (str1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}
