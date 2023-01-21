/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:46:58 by nlonka            #+#    #+#             */
/*   Updated: 2022/11/27 13:13:23 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putchar(unsigned char c, int *count)
{
	write(1, &c, 1);
	*count = *count + 1;
}

int	inting(int *count, va_list args, int *i)
{
	int	n;

	n = (va_arg(args, int));
	pf_putnbr(n, count);
	*i = *i + 1;
	return (1);
}

int	iffer(const char *format, va_list args, int *count, int *i)
{
	if (format[*i] == 'c')
		return (the_charade(count, args, i));
	if (format[*i] == 's')
		return (string_it(count, args, i));
	if (format[*i] == 'p')
		return (mr_pointy(count, args, i));
	if (format[*i] == 'd' || format[*i] == 'i')
		return (inting(count, args, i));
	if (format[*i] == 'u')
		return (the_unsung(count, args, i));
	if (format[*i] == 'x' || format[*i] == 'X')
		return (hexer(format[*i], count, args, i));
	return (0);
}

int	dealer(const char *format, va_list args, int *count, int *i)
{
	int	check;

	check = 0;
	*i = *i + 1;
	if (format[*i] == ' ')
	{
		write(1, " ", 1);
		*count = *count + 1;
		*i = *i + 1;
		while (format[*i] == ' ')
			*i = *i + 1;
	}
	check = iffer(format, args, count, i);
	if (check)
		return (1);
	if (format[*i] == '%')
	{
		write(1, "%", 1);
		*count = *count + 1;
		*i = *i + 1;
		return (1);
	}
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		check;

	check = 0;
	i = 0;
	count = 0;
	va_start (args, format);
	while (format[i])
	{
		if (format[i] == '%')
			check = dealer(format, args, &count, &i);
		else
		{
			write(1, &(format[i]), 1);
			count++;
			i++;
		}
		if (check < 0)
			return (-1);
	}
	va_end (args);
	return (count);
}
