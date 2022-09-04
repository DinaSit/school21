/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoyama <rkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 00:30:06 by rkoyama           #+#    #+#             */
/*   Updated: 2021/11/28 00:30:07 by rkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		fd2;
	char	*string;

	fd2 = open("nl", O_RDONLY);
	fd = open("text.txt", O_RDONLY);
	string = get_next_line(fd2);
	free(string);
	string = get_next_line(fd);
	printf("%s |\n", string);
	return (0);
}
