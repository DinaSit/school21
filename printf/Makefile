# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkoyama <rkoyama@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 15:01:40 by rkoyama           #+#    #+#              #
#    Updated: 2021/11/28 05:03:49 by rkoyama          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c ft_putnbr_fd.c
OBJS		= $(SRCS:.c=.o)

BONUS		= ft_printf_bonus.c ft_putnbr_fd.c
BONUS_OBJS	= $(BON	)

HEADER 		= libftprintf.h

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I.
TEMPF 		= .tempf

NAME		= libftprintf.a

all:		$(NAME)

$(OBJS):	$(HEADER)
$(BONUS_OBJS):	$(HEADER)

$(NAME):	$(OBJS)
			ar src $(NAME) $?

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)
			@${RM} ${TEMPF}

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

bonus: ${TEMPF}

${TEMPF}:	${NAME} ${BONUS_OBJS}
	ar rcs ${NAME} ${BONUS_OBJS} 
	@touch ${TEMPF}

.PHONY:			all clean fclean re bonus 