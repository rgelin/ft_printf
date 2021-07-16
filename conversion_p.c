/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:55:18 by rgelin            #+#    #+#             */
/*   Updated: 2021/07/16 13:37:13 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_adr(char *res, char *flag, t_flag *p_flag, t_len *length)
{
	int	i;

	i = 0;
	p_flag->size = ft_atoi_modified(flag);
	if (res && p_flag->size > (ft_strlen(res) + 2))
	{
		print_space_p(res, flag, p_flag, length);
		put_adr(res, flag, length);
	}
	else
	{
		put_adr(res, flag, length);
	}
	return ;
}

void	print_adr_neg(char *res, char *flag, t_flag *p_flag, t_len *length)
{
	int	i;

	i = 0;
	if (res && res == NULL && flag[ft_strlen(flag) - 2] == '.')
	{
		ft_putstr_fd("0x", 1);
		return ;
	}
	p_flag->size = ft_atoi_modified(flag);
	if (res && p_flag->size > (ft_strlen(res) + 2))
	{
		write(1, "0x", 2);
		ft_putstr_fd(res, 1);
		length->len += (ft_strlen(res) + 2);
		print_space_p(res, flag, p_flag, length);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(res, 1);
		length->len += (ft_strlen(res) + 2);
	}
	return ;
}

void	print_direction_p(char *res, char *flag, t_flag *p_flag, t_len *length)
{
	if (res && p_flag->minus == 1)
		print_adr_neg(res, flag, p_flag, length);
	else
		print_adr(res, flag, p_flag, length);
	free(res);
	return ;
}

void	convert_adr(va_list ap, char *flag, t_flag *p_flag, t_len *length)
{
	unsigned long	adr;
	char			*base;
	char			*res;
	int				i;

	adr = (unsigned long)va_arg(ap, void *);
	res = malloc(sizeof(char) * (count_nbr(adr) + 1));
	if (!res)
		return ;
	i = 0;
	if (!adr)
		res[i++] = '0';
	base = "0123456789abcdef";
	while (adr > 0)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i++;
	}
	res[i] = '\0';
	ft_swap(res);
	print_direction_p(res, flag, p_flag, length);
	return ;
}

int	conversion_p(va_list ap, char *flag, t_len *length)
{
	t_flag	*p_flag;

	p_flag = (t_flag *)malloc(sizeof(t_flag));
	if (!p_flag)
		return (-1);
	ini_struct_p(p_flag);
	activation_flag(flag, p_flag);
	convert_adr(ap, flag, p_flag, length);
	free(p_flag);
	free(flag);
	return (0);
}
