/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:13:01 by nlonka            #+#    #+#             */
/*   Updated: 2022/11/27 13:18:12 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	the_charade(int *count, va_list args, int *i)
{
	unsigned int	c;

	c = va_arg(args, unsigned int);
	pf_putchar(c, count);
	*i = *i + 1;
	return (1);
}

int	mr_pointy(int *count, va_list args, int *i)
{
	unsigned long long	n;
	int					check;

	n = va_arg(args, unsigned long long);
	write(1, "0x", 2);
	*count = *count + 2;
	*i = *i + 1;
	if (n != 0)
		check = the_hexing(n, count, 0, 32);
	else
	{
		check = 1;
		pf_putchar('0', count);
	}
	return (check);
}

int	the_unsung(int *count, va_list args, int *i)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	if (n < 0)
		n = -n;
	*i = *i + 1;
	pf_put_ung(n, count);
	return (1);
}

int	string_it(int *count, va_list args, int *i)
{
	int		loca;
	char	*str;

	loca = 0;
	str = va_arg(args, char *);
	*i = *i + 1;
	if (!str)
	{
		*count = *count + 6;
		write(1, "(null)", 6);
		return (1);
	}
	while (str[loca])
	{
		pf_putchar(str[loca], count);
		loca++;
	}
	return (1);
}	
