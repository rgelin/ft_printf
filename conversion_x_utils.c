/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_x_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:53:18 by rgelin            #+#    #+#             */
/*   Updated: 2021/07/16 13:24:04 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	define_nb_space_x(char *res, t_flag *p_flag)
{
	int	nb_space;

	nb_space = 0;
	if (res && res[0] == '-' && p_flag->precision > ft_strlen(res))
		p_flag->size--;
	if (res && res[0] == '0' && p_flag->precision == 0 && p_flag->dot == 1)
	{
		nb_space = p_flag->size;
		return (nb_space);
	}
	if (res && (p_flag->dot == 0 || p_flag->precision < ft_strlen(res)))
		nb_space = p_flag->size - ft_strlen(res);
	else
		nb_space = p_flag->size - p_flag->precision;
	return (nb_space);
}

void	print_zero_x(char *res, t_flag *p_flag, t_len *length)
{
	int	i;

	i = 0;
	if (!res)
		return ;
	if (p_flag->dot == 1 || p_flag->zero == 1)
	{
		while (i < (p_flag->precision - ft_strlen(res)))
		{
			ft_putchar_fd('0', 1);
			length->len++;
			i++;
		}
	}
}

void	print_space(int nb_space, t_len *length)
{
	int	i;

	i = 0;
	while (i < nb_space)
	{
		ft_putchar_fd(' ', 1);
		length->len++;
		i++;
	}
	return ;
}

void	print_x(char *res, t_flag *p_flag, t_len *length)
{
	int	i;
	int	nb_space;

	i = 0;
	if (!res)
		return ;
	nb_space = define_nb_space_x(res, p_flag);
	print_space(nb_space, length);
	if (res[0] == '0' && p_flag->precision == 0 && p_flag->dot == 1)
		return ;
	print_zero_x(res, p_flag, length);
	ft_putstr_fd(res, 1);
	length->len += ft_strlen(res);
	return ;
}

void	print_x_neg(char *res, t_flag *p_flag, t_len *length)
{
	int	i;
	int	nb_space;

	if (!res)
		return ;
	nb_space = define_nb_space_x(res, p_flag);
	i = 0;
	if (res[0] == '0' && p_flag->precision == 0 && p_flag->dot == 1)
		print_space(nb_space, length);
	else
	{
		print_zero_x(res, p_flag, length);
		ft_putstr_fd(res, 1);
		length->len += ft_strlen(res);
		print_space(nb_space, length);
	}
	return ;
}
