# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/12 16:40:01 by rgelin            #+#    #+#              #
#    Updated: 2021/07/12 13:16:58 by rgelin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c \
		conversion_c.c \
		conversion_d_utils_2.c \
		conversion_d_utils.c \
		conversion_d.c \
		conversion_p_utils.c \
		conversion_p.c \
		conversion_s_utils.c \
		conversion_s.c \
		conversion_u_utils.c \
		conversion_u.c \
		conversion_x_utils.c \
		conversion_x_utils_2.c \
		conversion_x.c \
		conversion_percent.c \
		conversion_percent_utils.c \
		flag.c \
		init_struct.c \
		libft_utils.c \
		libft_utils_2.c

OBJS        =       $(SRCS:%.c=%.o)

CC          =       gcc

CFLAGS      =       -Wall -Wextra -Werror

REMOVE		=		rm -f

NAME        =       libftprintf.a

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
			
all:		$(NAME)

$(NAME):	$(OBJS)
			@ar rc  $(NAME) $(OBJS)

clean:
			@$(REMOVE) $(OBJS)

fclean:		clean
			@$(REMOVE) $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re .c.o