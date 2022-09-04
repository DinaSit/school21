/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoyama <rkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:53:35 by rkoyama           #+#    #+#             */
/*   Updated: 2021/11/28 00:31:38 by rkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_endl_fd(char *t);

char	*ft_read_fd(int fd, char *str)
{
	int		rd;
	char	buff[BUFFER_SIZE + 1];
	char	*temp;

	*buff = '\0';
	rd = 1;
	while (!ft_endl_fd(buff) && rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd < 0)
			return (NULL);
		if (rd > 0 && !str)
			str = (char *)malloc(sizeof(char));
		buff[rd] = '\0';
		temp = str;
		str = ft_strjoin(str, buff);
		free(temp);
	}
	return (str);
}

char	*ft_write_before_n(char *str)
{
	char	*res;
	int		size;

	if (!*str)
		return (NULL);
	size = 0;
	while (str[size] != '\n' && str[size])
		++size;
	res = (char *)malloc(sizeof(char) * (size + 2));
	size = 0;
	while (str[size] != '\n' && str[size])
	{
		res[size] = str[size];
		++size;
	}
	if (!str[size])
		res[size] = '\0';
	else
	{
		res[size] = '\n';
		res[size + 1] = '\0';
	}
	return (res);
}

char	*ft_write_after_n(char *str)
{
	int		index;
	char	*new;

	index = 0;
	while (str[index] != '\n' && str[index])
		++index;
	if (str[index])
		++index;
	else
	{
		free(str);
		return (NULL);
	}
	new = ft_strdup(&(str[index]));
	free(str);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*line[MAX_OPEN];
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd] = ft_read_fd(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	res = ft_write_before_n(line[fd]);
	line[fd] = ft_write_after_n(line[fd]);
	return (res);
}

int	ft_endl_fd(char *t)
{
	while (*t)
	{
		if (*(t++) == '\n')
			return (1);
	}
	return (0);
}
