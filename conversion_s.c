/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 21:44:14 by rgelin            #+#    #+#             */
/*   Updated: 2021/03/26 16:07:06 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flag_dot_s(va_list ap, char *flag, t_flag *p_flag, t_len *length)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = va_arg(ap, char *)))
		str = "(null)";
	while (flag[i] != '.')
		i++;
	if (flag[ft_strlen(flag) - 2] == '.')
		p_flag->precision = 0;
	else
		p_flag->precision = ft_atoi_modified(&flag[i]);
	if (flag[0] == '.' || (flag[1] == '.' && flag[0] == '-'))
		p_flag->size = 0;
	else
		p_flag->size = ft_atoi_modified(flag);
	print_neg_direction_s(str, p_flag, length);
	return ;
}

void	print_string_star_2(va_list ap, t_flag *p_flag, t_len *length)
{
	char *str;

	p_flag->size = va_arg(ap, int);
	p_flag->precision = va_arg(ap, int);
	if (p_flag->size < 0)
	{
		p_flag->minus = 1;
		p_flag->size = -p_flag->size;
	}
	if (!(str = va_arg(ap, char *)))
		str = "(null)";
	if (p_flag->precision < 0)
		p_flag->precision = ft_strlen(str);
	print_neg_direction_s(str, p_flag, length);
	return ;
}

void	print_string_star_1(va_list ap, char *flag, t_flag *p_flag,
							t_len *length)
{
	char *str;

	set_one_star_arg_s(ap, flag, p_flag);
	if (!(str = va_arg(ap, char *)))
		str = "(null)";
	if (p_flag->precision < 0)
	{
		p_flag->size = ft_strlen(str);
		p_flag->precision = p_flag->size;
	}
	print_neg_direction_s(str, p_flag, length);
	return ;
}

void	print_s(va_list ap, char *flag, t_flag *p_flag, t_len *length)
{
	char *str;

	if (!(p_flag->size = ft_atoi_modified(flag)))
		p_flag->size = 0;
	p_flag->precision = 0;
	if (!(str = va_arg(ap, char *)))
		str = "(null)";
	if ((p_flag->size < ft_strlen(str)))
		p_flag->size = ft_strlen(str);
	print_neg_direction_s(str, p_flag, length);
	return ;
}

int		conversion_s(va_list ap, char *flag, t_len *length)
{
	t_flag *p_flag;

	if (!(p_flag = (t_flag*)malloc(sizeof(t_flag))))
		return (-1);
	ini_struct_p(p_flag);
	activation_flag(flag, p_flag);
	if (p_flag->star == 2)
		print_string_star_2(ap, p_flag, length);
	if (p_flag->star == 1)
		print_string_star_1(ap, flag, p_flag, length);
	else if (p_flag->dot == 1 && p_flag->star == 0)
		print_flag_dot_s(ap, flag, p_flag, length);
	else if (p_flag->dot == 0 && p_flag->star == 0)
		print_s(ap, flag, p_flag, length);
	free(p_flag);
	free(flag);
	return (0);
}
