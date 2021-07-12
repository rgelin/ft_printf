/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_percent_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:05:35 by rgelin            #+#    #+#             */
/*   Updated: 2021/07/12 17:50:36 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent_star_1(t_flag *p_flag, t_len *length)
{
	if (p_flag->minus == 1)
		print_percent_neg(p_flag, length);
	else
		print_percent(p_flag, length);
	return ;
}

void	print_percent(t_flag *p_flag, t_len *length)
{
	int	i;
	int	nb_space;

	i = 0;
	nb_space = p_flag->size - 1;
	while (i < nb_space)
	{
		ft_putchar_fd(' ', 1);
		length->len++;
		i++;
	}
	i = 0;
	if (p_flag->zero == 1)
	{
		while (i < (p_flag->precision - 1))
		{
			ft_putchar_fd('0', 1);
			length->len++;
			i++;
		}
	}
	ft_putchar_fd('%', 1);
	length->len++;
	return ;
}

void	print_percent_neg(t_flag *p_flag, t_len *length)
{
	int	i;

	i = 0;
	if (p_flag->zero == 1)
	{
		while (i < (p_flag->precision - 1))
		{
			ft_putchar_fd('0', 1);
			length->len++;
			i++;
		}
	}
	ft_putchar_fd('%', 1);
	length->len++;
	while (i < (p_flag->size - 1))
	{
		ft_putchar_fd(' ', 1);
		length->len++;
		i++;
	}
	return ;
}
