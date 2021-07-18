/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:31:23 by rgelin            #+#    #+#             */
/*   Updated: 2021/07/18 17:31:36 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_flag(const char *format)
{
	int	i;

	i = 0;
	while (!ft_strchr("cspdiuxX%", format[i]))
		i++;
	return (i);
}

char	*extract_flag(const char *format, int i, t_len *length)
{
	int		j;
	char	*res;

	j = 0;
	res = malloc(sizeof(char) * count_flag(format) + 1);
	if (res == NULL)
	{
		length->len = -1;
		return (NULL);
	}
	while (!ft_strchr("cspdiuxX%", format[i]))
		res[j++] = format[i++];
	res[j++] = format[i++];
	res[j] = '\0';
	return (res);
}

int	activation_flag(char *flag, t_flag *active_flag)
{
	int	i;

	i = 0;
	if (!flag)
		return (0);
	while (flag[i])
	{
		if (flag[i] == '.')
			active_flag->dot = 1;
		if (flag[i] == '-')
			active_flag->minus = 1;
		if (flag[i] == '*')
			active_flag->star += 1;
		i++;
	}
	if (active_flag->dot == 0)
	{
		if (flag[0] == '0')
			active_flag->zero = 1;
	}
	return (0);
}

void	print_direction(va_list ap, char *flag, t_len *length)
{
	if (flag[ft_strlen(flag) - 1] == 'c')
		conversion_c(ap, flag, length);
	if (flag[ft_strlen(flag) - 1] == 's')
		conversion_s(ap, flag, length);
	if (flag[ft_strlen(flag) - 1] == 'p')
		conversion_p(ap, flag, length);
	if (flag[ft_strlen(flag) - 1] == 'd')
		conversion_d(ap, flag, length);
	if (flag[ft_strlen(flag) - 1] == 'i')
		conversion_d(ap, flag, length);
	if (flag[ft_strlen(flag) - 1] == 'u')
		conversion_u(ap, flag, length);
	if (flag[ft_strlen(flag) - 1] == 'x')
		conversion_x(ap, flag, length);
	if (flag[ft_strlen(flag) - 1] == 'X')
		conversion_x(ap, flag, length);
	if (flag[ft_strlen(flag) - 1] == '%')
		conversion_percent(ap, flag, length);
	return ;
}
