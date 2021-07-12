/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_d_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:47:12 by rgelin            #+#    #+#             */
/*   Updated: 2021/07/12 17:48:14 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_size_one_star(va_list ap, char *flag, t_flag *p_flag)
{
	p_flag->precision = va_arg(ap, int);
	p_flag->size = ft_atoi_modified(flag);
	if (!p_flag->size)
		p_flag->size = 0;
	if (p_flag->precision < 0 && p_flag->zero == 1)
	{
		p_flag->size = p_flag->precision;
		p_flag->precision = 0;
	}
	return ;
}

void	set_one_star_arg(va_list ap, char *flag, t_flag *p_flag, t_len *length)
{
	long	nb;

	if ((flag[ft_strlen(flag) - 2] == '*' && p_flag->dot == 1)
		|| (p_flag->zero == 1))
		set_size_one_star(ap, flag, p_flag);
	else
	{
		p_flag->size = va_arg(ap, int);
		p_flag->precision = ft_atoi_modified(flag);
		if (!p_flag->precision)
			p_flag->precision = 0;
	}
	nb = (long)va_arg(ap, int);
	if (p_flag->size < 0)
	{
		p_flag->minus = 1;
		p_flag->size = -p_flag->size;
	}
	print_neg_direction(nb, p_flag, length);
	return ;
}
