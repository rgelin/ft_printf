/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:33:24 by rgelin            #+#    #+#             */
/*   Updated: 2021/03/18 18:38:24 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_swap(char *res)
{
	int		i;
	char	temp;

	i = 0;
	while (i < ft_strlen(res) / 2)
	{
		temp = res[i];
		res[i] = res[ft_strlen(res) - i - 1];
		res[ft_strlen(res) - i - 1] = temp;
		i++;
	}
}

int		ft_atoi_modified(char *str)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == ' '
			|| str[i] == '-' || str[i] == '0' || str[i] == '*' || str[i] == '.')
		i++;
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		res = (res * 10) + str[i++] - '0';
		if (res < 0)
			return (sign == 1 ? -1 : 0);
	}
	return (int)(sign * res);
}

void	ft_putnbr_unsigned_fd(unsigned long nb, int fd)
{
	if (nb > 9)
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putchar_fd((nb % 10) + '0', fd);
	}
	else
		ft_putchar_fd(nb + '0', fd);
}

int		count_nbr_u(unsigned long nb)
{
	int count;

	count = 0;
	if (nb == 0)
		count = 1;
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}
