/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:24:02 by rgelin            #+#    #+#             */
/*   Updated: 2021/07/16 13:30:29 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flag_dot_x(va_list ap, char *flag, t_flag *p_flag, t_len *length)
{
	int		i;
	char	*nb;

	i = 0;
	p_flag->size = ft_atoi_modified(flag);
	while (flag[i] != '.')
		i++;
	p_flag->precision = ft_atoi_modified(&flag[i]);
	if (!p_flag->size)
		p_flag->size = p_flag->precision;
	nb = convert_nbr(ap, flag);
	if (nb && p_flag->minus == 1)
		print_x_neg(nb, p_flag, length);
	else
		print_x(nb, p_flag, length);
	free(nb);
	return ;
}

void	print_x_star_2(va_list ap, char *flag, t_flag *p_flag, t_len *length)
{
	char	*nb;

	p_flag->size = va_arg(ap, int);
	p_flag->precision = va_arg(ap, int);
	nb = convert_nbr(ap, flag);
	if (nb && p_flag->minus == 1)
		print_x_neg(nb, p_flag, length);
	else
		print_x(nb, p_flag, length);
	free(nb);
	return ;
}

void	set_x_star_arg(va_list ap, char *flag, t_flag *p_flag, t_len *length)
{
	char	*nb;

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
	nb = convert_nbr(ap, flag);
	if (!nb)
		return ;
	print_x_star_1(nb, p_flag, length);
	return ;
}

void	convert_x(va_list ap, char *flag, t_flag *p_flag, t_len *length)
{
	char	*nb;

	p_flag->size = ft_atoi_modified(flag);
	if (!p_flag->size)
		p_flag->size = 0;
	p_flag->precision = 0;
	if (p_flag->zero == 1)
	{
		p_flag->precision = p_flag->size;
		p_flag->size = 0;
	}
	nb = convert_nbr(ap, flag);
	if (nb && p_flag->minus == 1)
		print_x_neg(nb, p_flag, length);
	else
		print_x(nb, p_flag, length);
	free(nb);
	return ;
}

int	conversion_x(va_list ap, char *flag, t_len *length)
{
	t_flag		*p_flag;

	p_flag = (t_flag *)malloc(sizeof(t_flag));
	if (!p_flag)
		return (-1);
	ini_struct_p(p_flag);
	activation_flag(flag, p_flag);
	if (p_flag->star == 2)
		print_x_star_2(ap, flag, p_flag, length);
	if (p_flag->star == 1)
		set_x_star_arg(ap, flag, p_flag, length);
	else if (p_flag->dot == 1 && p_flag->star == 0)
		print_flag_dot_x(ap, flag, p_flag, length);
	else if (p_flag->dot == 0 && p_flag->star == 0)
		convert_x(ap, flag, p_flag, length);
	free(p_flag);
	free(flag);
	return (0);
}
