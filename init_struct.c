/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:28:36 by rgelin            #+#    #+#             */
/*   Updated: 2021/03/18 17:03:21 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ini_struct_p(t_flag *flag)
{
	flag->dot = 0;
	flag->minus = 0;
	flag->zero = 0;
	flag->star = 0;
}

void	ini_struct_len(t_len *length)
{
	length->len = 0;
}
