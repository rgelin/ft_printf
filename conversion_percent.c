/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:01:57 by rgelin            #+#    #+#             */
/*   Updated: 2021/07/12 17:52:07 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent_dot(char *flag, t_flag *p_flag, t_len *length)
{
	int	i;

	i = 0;
	p_flag->size = ft_atoi_modified(flag);
	while (flag[i] != '.')
		i++;
	p_flag->precision = ft_atoi_modified(&flag[i]);
	if (!p_flag->size)
		p_flag->size = p_flag->precision;
	if (p_flag->minus == 1)
		print_percent_neg(p_flag, length);
	else
		print_percent(p_flag, length);
	return ;
}

void	print_percent_star_2(va_list ap, t_flag *p_flag, t_len *length)
{
	p_flag->size = va_arg(ap, int);
	p_flag->precision = va_arg(ap, int);
	if (p_flag->minus == 1)
		print_percent_neg(p_flag, length);
	else
		print_percent(p_flag, length);
	return ;
}

void	set_arg_star_1(va_list ap, char *flag, t_flag *p_flag, t_len *length)
{
	if (flag[0] == '*' || flag[1] == '*')
	{
		if (p_flag->zero == 1)
		{
			p_flag->precision = va_arg(ap, int);
			p_flag->size = 0;
		}
		else
		{
			p_flag->precision = ft_atoi_modified(flag);
			p_flag->size = va_arg(ap, int);
		}
	}
	else
	{
		p_flag->size = ft_atoi_modified(flag);
		p_flag->precision = va_arg(ap, int);
	}
	print_percent_star_1(p_flag, length);
}

void	print_per(char *flag, t_flag *p_flag, t_len *length)
{
	p_flag->size = ft_atoi_modified(flag);
	if (!p_flag->size)
		p_flag->size = 0;
	p_flag->precision = 0;
	if (p_flag->zero == 1)
	{
		p_flag->precision = p_flag->size;
		p_flag->size = 0;
	}
	if (p_flag->minus == 1)
		print_percent_neg(p_flag, length);
	else
		print_percent(p_flag, length);
	return ;
}

int	conversion_percent(va_list ap, char *flag, t_len *length)
{
	t_flag	*p_flag;

	p_flag = (t_flag *)malloc(sizeof(t_flag));
	if (!p_flag)
		return (-1);
	ini_struct_p(p_flag);
	activation_flag(flag, p_flag);
	if (p_flag->star == 2)
		print_percent_star_2(ap, p_flag, length);
	if (p_flag->star == 1)
		set_arg_star_1(ap, flag, p_flag, length);
	else if (p_flag->dot == 1 && p_flag->star == 0)
		print_percent_dot(flag, p_flag, length);
	else if (p_flag->dot == 0 && p_flag->star == 0)
		print_per(flag, p_flag, length);
	free(p_flag);
	free(flag);
	return (0);
}
