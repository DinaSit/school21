/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoyama <rkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 00:54:41 by rkoyama           #+#    #+#             */
/*   Updated: 2021/11/28 05:38:25 by rkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define	LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putnbr_fd(long long n, int fd);
int	ft_convert_base(unsigned long long int n, const char *base);
int	ft_putstr(char *str);
int	ft_define_arg(va_list ap, char c);
int	ft_printf(const char *str, ...);

#endif