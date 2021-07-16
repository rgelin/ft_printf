/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_p_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:18:19 by rgelin            #+#    #+#             */
/*   Updated: 2021/07/15 22:14:43 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nb_space_p(char *res, char *flag, t_flag *p_flag)
{
	int	nb_space;

	nb_space = 0;
	if (res && res[0] == '0' && flag[ft_strlen(flag) - 2] == '.')
		nb_space = p_flag->size - 2;
	else
		nb_space = p_flag->size - (ft_strlen(res) + 2);
	return (nb_space);
}

void	put_adr(char *res, char *flag, t_len *length)
{
	ft_putstr_fd("0x", 1);
	if (res && res[0] == '0' && flag[ft_strlen(flag) - 2] == '.')
	{
		length->len += 2;
		return ;
	}
	else
	{
		ft_putstr_fd(res, 1);
		length->len += (ft_strlen(res) + 2);
	}
}

void	print_space_p(char *res, char *flag, t_flag *p_flag, t_len *length)
{
	int	i;

	i = 0;
	while (res && i++ < nb_space_p(res, flag, p_flag))
	{
		ft_putchar_fd(' ', 1);
		length->len++;
	}
}
