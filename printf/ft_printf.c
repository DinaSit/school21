/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoyama <rkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 00:55:32 by rkoyama           #+#    #+#             */
/*   Updated: 2021/11/28 06:05:42 by rkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_convert_base(unsigned long long int n, const char *base)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_convert_base(n / 16, base);
	i += write(1, &base[n % 16], 1);
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if(!str)
	{
		i += ft_putstr("(null)");
		return (i);
	}
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_define_arg(va_list ap, char c)
{
	int		i;
	char	sim;

	i = 0;
	if (c == 'c')
	{
		sim = va_arg(ap, int);
		i += write (1, &sim, 1);
	}
	if (c == 's')
		i += ft_putstr(va_arg(ap, char *));
	if (c == 'p')
	{
		i += write(1, "0x", 2);
		i += ft_convert_base(va_arg(ap,unsigned long long int), "0123456789abcdef");
	}
	if (c == 'u')
		i += ft_putnbr_fd(va_arg(ap, unsigned int), 1);
	if (c == 'i' || c == 'd')
		i += ft_putnbr_fd(va_arg(ap, int), 1);
	if (c == 'x')
		i += ft_convert_base(va_arg(ap, unsigned int), "0123456789abcdef");
	if (c == 'X')
		i += ft_convert_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	if (c == '%')
		i += write (1, "%", 1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, str);
	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			i += ft_define_arg(ap, str[1]);
			str += 2;
		}
		else if (*str)
			i += write(1, str++, 1);
		//printf("2==%d==\n", i);
	}
	va_end(ap);
	return (i);
}

// int	main(void)
// {
// 	char c = 1;

// 	printf("%%%%\n");
// 	ft_printf("%%%%\n");
// 	return (0);
// }
