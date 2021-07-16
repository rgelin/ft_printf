/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:18:50 by rgelin            #+#    #+#             */
/*   Updated: 2021/07/15 22:05:29 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_neg_direction_s(char *str, t_flag *p_flag, t_len *length)
{
	if (str && p_flag->minus == 1)
		print_string_neg(str, p_flag, length);
	else
		print_string(str, p_flag, length);
	return ;
}

void	set_one_star_arg_s(va_list ap, char *flag, t_flag *p_flag)
{
	if (p_flag->dot == 1 && flag[ft_strlen(flag) - 2] == '*')
	{
		p_flag->size = ft_atoi_modified(flag);
		if (!p_flag->size)
			p_flag->size = 0;
		p_flag->precision = va_arg(ap, int);
	}
	else
	{
		p_flag->size = va_arg(ap, int);
		p_flag->precision = ft_atoi_modified(flag);
		if (!p_flag->precision)
			p_flag->precision = 0;
	}
	if (p_flag->size < 0)
	{
		p_flag->minus = 1;
		p_flag->size = -p_flag->size;
	}
	return ;
}

void	print_space_s(char *str, t_flag *p_flag, t_len *length)
{
	int	i;

	i = 0;
	if (str && ((p_flag->precision < ft_strlen(str))) && (p_flag->dot == 1))
	{
		while (i++ < ((p_flag->size - p_flag->precision)))
		{
			ft_putchar_fd(' ', 1);
			length->len++;
		}
	}
	else
	{
		while (i++ < (p_flag->size - ft_strlen(str)))
		{
			ft_putchar_fd(' ', 1);
			length->len++;
		}
	}
	return ;
}

void	print_string(char *str, t_flag *p_flag, t_len *length)
{
	int	i;

	i = 0;
	if (str && ((p_flag->precision < ft_strlen(str))) && (p_flag->dot == 1))
	{
		print_space_s(str, p_flag, length);
		while (i < p_flag->precision)
		{
			ft_putchar_fd(str[i++], 1);
			length->len++;
		}
	}
	else
	{
		print_space_s(str, p_flag, length);
		ft_putstr_fd(str, 1);
		length->len += ft_strlen(str);
	}
	return ;
}

void	print_string_neg(char *str, t_flag *p_flag, t_len *length)
{
	int	i;

	i = 0;
	if (str && (p_flag->precision < ft_strlen(str)) && (p_flag->dot == 1))
	{
		while (i < p_flag->precision)
		{
			ft_putchar_fd(str[i++], 1);
			length->len++;
		}
		i = 0;
		print_space_s(str, p_flag, length);
	}
	else
	{
		ft_putstr_fd(str, 1);
		length->len += ft_strlen(str);
		print_space_s(str, p_flag, length);
	}
	return ;
}
