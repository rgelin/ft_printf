/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_x_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:12:04 by rgelin            #+#    #+#             */
/*   Updated: 2021/07/19 00:46:43 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_x_star_1(char *nb, t_flag *p_flag, t_len *length)
{
	if (nb && p_flag->minus == 1)
		print_x_neg(nb, p_flag, length);
	else
		print_x(nb, p_flag, length);
	free(nb);
	return ;
}

char	*convert_nbr(va_list ap, char *flag)
{
	unsigned long	nbr;
	char			*base;
	char			*res;
	int				i;

	i = 0;
	nbr = (unsigned long)va_arg(ap, unsigned int);
	res = malloc(sizeof(char) * count_nbr(nbr) + 1);
	if (!res)
		return (NULL);
	if (nbr == 0)
		res[i++] = '0';
	if (flag[ft_strlen(flag) - 1] == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	while (nbr > 0)
	{
		res[i] = base[(nbr % 16)];
		nbr /= 16;
		i++;
	}
	res[i] = '\0';
	ft_swap(res);
	return (res);
}
