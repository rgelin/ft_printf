/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:48:41 by rgelin            #+#    #+#             */
/*   Updated: 2021/07/12 17:45:36 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_neg_direction(long nb, t_flag *p_flag, t_len *length)
{
	if (p_flag->minus == 1)
		print_nb_neg(nb, p_flag, length);
	else
		print_nb(nb, p_flag, length);
	return ;
}

void	print_flag_dot(va_list ap, char *flag, t_flag *p_flag, t_len *length)
{
	int		i;
	long	nb;

	i = 0;
	while (flag[i] != '.')
		i++;
	if (flag[ft_strlen(flag) - 2] == '.')
		p_flag->precision = 0;
	else
		p_flag->precision = ft_atoi_modified(&flag[i]);
	nb = (long)va_arg(ap, int);
	if (flag[0] == '.' || (flag[1] == '.' && flag[0] == '-'))
		p_flag->size = 0;
	else
		p_flag->size = ft_atoi_modified(flag);
	print_neg_direction(nb, p_flag, length);
	return ;
}

void	print_star_2(va_list ap, t_flag *p_flag, t_len *length)
{
	long	nb;

	p_flag->size = va_arg(ap, int);
	p_flag->precision = va_arg(ap, int);
	nb = (long)va_arg(ap, int);
	print_neg_direction(nb, p_flag, length);
	return ;
}

void	print_d(va_list ap, char *flag, t_flag *p_flag, t_len *length)
{
	long	nb;

	nb = (long)va_arg(ap, int);
	p_flag->size = ft_atoi_modified(flag);
	if (!p_flag->size)
		p_flag->size = 0;
	p_flag->precision = 0;
	if (p_flag->zero == 1)
	{
		p_flag->precision = p_flag->size;
		p_flag->size = 0;
	}
	print_neg_direction(nb, p_flag, length);
	return ;
}

int	conversion_d(va_list ap, char *flag, t_len *length)
{
	t_flag	*p_flag;

	p_flag = (t_flag *)malloc(sizeof(t_flag));
	if (!p_flag)
		return (-1);
	ini_struct_p(p_flag);
	activation_flag(flag, p_flag);
	if (p_flag->star == 2)
		print_star_2(ap, p_flag, length);
	if (p_flag->star == 1)
		set_one_star_arg(ap, flag, p_flag, length);
	else if (p_flag->dot == 1 && p_flag->star == 0)
		print_flag_dot(ap, flag, p_flag, length);
	else if (p_flag->dot == 0 && p_flag->star == 0)
		print_d(ap, flag, p_flag, length);
	free(p_flag);
	free(flag);
	return (0);
}
