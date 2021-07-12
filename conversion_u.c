/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:48:41 by rgelin            #+#    #+#             */
/*   Updated: 2021/07/12 18:00:55 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flag_dot_u(va_list ap, char *flag, t_flag *p_flag, t_len *length)
{
	int				i;
	unsigned long	nb;

	i = 0;
	p_flag->size = ft_atoi_modified(flag);
	while (flag[i] != '.')
		i++;
	if (flag[ft_strlen(flag) - 2] == '.')
		p_flag->precision = 0;
	else
		p_flag->precision = ft_atoi_modified(&flag[i]);
	nb = (unsigned long)va_arg(ap, unsigned int);
	if (flag[0] == '.' || (flag[1] == '.' && flag[0] == '-'))
		p_flag->size = 0;
	else
		p_flag->size = ft_atoi_modified(flag);
	print_neg_direction_u(nb, p_flag, length);
	return ;
}

void	print_u_star_2(va_list ap, t_flag *p_flag, t_len *length)
{
	unsigned long	nb;

	p_flag->size = va_arg(ap, int);
	p_flag->precision = va_arg(ap, unsigned int);
	nb = (unsigned long)va_arg(ap, unsigned int);
	print_neg_direction_u(nb, p_flag, length);
	return ;
}

void	set_u_star_arg(va_list ap, char *flag, t_flag *p_flag, t_len *length)
{
	unsigned long	nb;

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
	nb = (unsigned long)va_arg(ap, unsigned int);
	print_neg_direction_u(nb, p_flag, length);
	return ;
}

void	print_unsigned(va_list ap, char *flag, t_flag *p_flag, t_len *length)
{
	unsigned long	nb;

	p_flag->size = ft_atoi_modified(flag);
	if (!p_flag->size)
		p_flag->size = 0;
	p_flag->precision = 0;
	if (p_flag->zero == 1)
	{
		p_flag->precision = p_flag->size;
		p_flag->size = 0;
	}
	nb = (unsigned long)va_arg(ap, unsigned int);
	print_neg_direction_u(nb, p_flag, length);
	return ;
}

int	conversion_u(va_list ap, char *flag, t_len *length)
{
	t_flag	*p_flag;

	p_flag = (t_flag *)malloc(sizeof(t_flag));
	if (!p_flag)
		return (-1);
	ini_struct_p(p_flag);
	activation_flag(flag, p_flag);
	if (p_flag->star == 2)
		print_u_star_2(ap, p_flag, length);
	else if (p_flag->star == 1)
		set_u_star_arg(ap, flag, p_flag, length);
	else if (p_flag->dot == 1 && p_flag->star == 0)
		print_flag_dot_u(ap, flag, p_flag, length);
	else
		print_unsigned(ap, flag, p_flag, length);
	free(p_flag);
	free(flag);
	return (0);
}
