/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoyama <rkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:53:39 by rkoyama           #+#    #+#             */
/*   Updated: 2021/11/28 00:32:10 by rkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h> //delete
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define	BUFFER_SIZE 5
# endif
# define MAX_OPEN 10000

typedef struct s_list
{
	int				a;
	void			*content;
	struct s_list	*next;
}			t_list;

typedef struct s_dickscriptor
{
	int						fd;
	char					*content;
	struct s_dickscriptor	*next;
}			t_dickscriptor;

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *str);

#endif
