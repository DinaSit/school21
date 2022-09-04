/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkoyama <rkoyama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:53:39 by rkoyama           #+#    #+#             */
/*   Updated: 2021/11/28 00:22:06 by rkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define	BUFFER_SIZE 5
# endif

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
