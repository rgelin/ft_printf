/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:25:29 by rgelin            #+#    #+#             */
/*   Updated: 2021/07/12 18:15:09 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_strlen(char *str);
void			ft_putchar_fd(int c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *str, int fd);
int				ft_atoi_modified(char *str);
int				ft_strchr(char *s, int c);
void			ft_swap(char *res);
void			ft_putnbr_unsigned_fd(unsigned long n, int fd);
int				count_nbr_u(unsigned long nb);

typedef struct s_len
{
	int	len;
}				t_len;

typedef struct s_flag
{
	int	dot;
	int	minus;
	int	zero;
	int	star;

	int	size;
	int	precision;
}				t_flag;

int				ft_printf(const char *format, ...);
char			*extract_flag(const char *format, int i);
void			ini_struct_p(t_flag *flag);
void			ini_struct_len(t_len *length);
int				activation_flag(char *flag, t_flag *active_flag);
void			print_direction(va_list ap, char *flag, t_len *length);

void			print_space(int nb_space, t_len *length);

int				conversion_d(va_list ap, char *flag, t_len *length);
void			set_size_one_star(va_list ap, char *flag, t_flag *p_flag);
void			set_one_star_arg(va_list ap, char *flag, t_flag *p_flag,
					t_len *length);
void			print_neg_direction(long nb, t_flag *p_flag, t_len *length);
void			print_nb(long nb, t_flag *p_flag, t_len *length);
void			print_nb_neg(long nb, t_flag *p_flag, t_len *length);

int				conversion_x(va_list ap, char *flag, t_len *length);
void			print_x_neg(char *res, t_flag *p_flag, t_len *length);
void			print_x(char *res, t_flag *p_flag, t_len *length);
char			*convert_nbr(va_list ap, char *flag);
int				count_nbr(long nb);
void			print_x_star_1(char *nb, t_flag *p_flag, t_len *length);

int				conversion_s(va_list ap, char *flag, t_len *length);
void			print_neg_direction_s(char *str, t_flag *p_flag, t_len *length);
void			set_one_star_arg_s(va_list ap, char *flag, t_flag *p_flag);
void			print_string(char *str, t_flag *p_flag, t_len *length);
void			print_string_neg(char *str, t_flag *p_flag, t_len *length);

int				conversion_c(va_list ap, char *flag, t_len *length);

int				conversion_p(va_list ap, char *flag, t_len *length);
int				nb_space_p(char *res, char *flag, t_flag *p_flag);
void			put_adr(char *res, char *flag, t_len *length);
void			print_space_p(char *res, char *flag, t_flag *p_flag,
					t_len *length);

int				conversion_u(va_list ap, char *flag, t_len *length);
void			print_u(unsigned long nb, t_flag *p_flag, t_len *length);
void			print_u_neg(unsigned long nb, t_flag *p_flag, t_len *length);
void			print_neg_direction_u(unsigned long nb, t_flag *p_flag,
					t_len *length);

int				conversion_percent(va_list ap, char *flag, t_len *length);
void			print_percent_star_1(t_flag *p_flag, t_len *length);
void			print_percent(t_flag *p_flag, t_len *length);
void			print_percent_neg(t_flag *p_flag, t_len *length);

#endif
