/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 10:15:32 by rgelin            #+#    #+#             */
/*   Updated: 2021/03/18 22:31:46 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(char c, t_flag *p_flag, t_len *length)
{
	int i;

	i = 0;
	while (i++ < (p_flag->size - 1))
	{
		ft_putchar_fd(' ', 1);
		length->len++;
	}
	ft_putchar_fd(c, 1);
	length->len++;
}

void	print_c_neg(char c, t_flag *p_flag, t_len *length)
{
	int i;

	i = 0;
	ft_putchar_fd(c, 1);
	length->len++;
	while (i++ < (p_flag->size - 1))
	{
		ft_putchar_fd(' ', 1);
		length->len++;
	}
}

void	print_c_star_1(va_list ap, t_flag *p_flag, t_len *length)
{
	char	c;

	p_flag->size = va_arg(ap, int);
	c = (char)va_arg(ap, int);
	if (p_flag->minus == 1)
		print_c_neg(c, p_flag, length);
	else
		print_c(c, p_flag, length);
}

void	print_char(va_list ap, char *flag, t_flag *p_flag, t_len *length)
{
	char	c;

	if (flag[ft_strlen(flag) - 1] == '%')
		c = '%';
	else
		c = (char)va_arg(ap, int);
	p_flag->size = ft_atoi_modified(flag);
	if (p_flag->minus == 1)
		print_c_neg(c, p_flag, length);
	else
		print_c(c, p_flag, length);
}

int		conversion_c(va_list ap, char *flag, t_len *length)
{
	t_flag *p_flag;

	if (!(p_flag = (t_flag*)malloc(sizeof(t_flag))))
		return (-1);
	ini_struct_p(p_flag);
	activation_flag(flag, p_flag);
	if (p_flag->star == 1)
		print_c_star_1(ap, p_flag, length);
	else
		print_char(ap, flag, p_flag, length);
	free(p_flag);
	free(flag);
	return (0);
}
