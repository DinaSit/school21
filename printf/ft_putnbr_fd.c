/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoyama <rkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:54:00 by rkoyama           #+#    #+#             */
/*   Updated: 2021/11/28 04:57:20 by rkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_fd(long long n, int fd)
{
	int				i;
	unsigned int	a;
	char			simb;

	i = 0;
	if (n < 0)
	{
		i += write(fd, "-", 1);
		a = n * (-1);
	}
	else
		a = n;
	if (a < 10 && a >= 0)
	{
		simb = a + '0';
		i += write(fd, &simb, 1);
	}
	else if (a >= 10)
	{
		simb = a % 10 + '0';
		i += ft_putnbr_fd((a / 10), fd);
		i += write(fd, &simb, 1);
	}
	return (i);
}
