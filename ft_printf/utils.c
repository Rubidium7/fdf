/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:46:58 by nlonka            #+#    #+#             */
/*   Updated: 2022/11/27 13:18:56 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_put_ung(unsigned long long nb, int *count)
{
	if (nb / 10)
		pf_put_ung(nb / 10, count);
	pf_putchar(nb % 10 + '0', count);
}

void	pf_putnbr(long long nb, int *count)
{
	if (nb < 0)
	{
		pf_putchar('-', count);
		nb = -nb;
	}
	if (nb / 10)
		pf_putnbr(nb / 10, count);
	pf_putchar(nb % 10 + '0', count);
}

int	the_hexing(unsigned long long n, int *count, int loca, int x)
{	
	char	*ans;
	int		h;

	ans = (char *) malloc(sizeof(char) * hexize(n));
	if (ans == NULL)
		return (0);
	while (n != 0)
	{
		h = n % 16;
		if (h < 10)
			h = h + 48;
		else
			h = h + 55 + x;
		ans[loca] = h;
		loca++;
		n = n / 16;
	}
	loca--;
	while (loca != -1)
	{
		pf_putchar(ans[loca], count);
		loca--;
	}
	free(ans);
	return (1);
}

int	hexize(unsigned long long n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n = n / 16;
		count++;
	}
	if (count == 0)
		return (1);
	return (count);
}

int	hexer(const char c, int *count, va_list args, int *i)
{
	unsigned int		n;
	int					check;
	int					x;

	x = 0;
	if (c == 'x')
		x = 32;
	*i = *i + 1;
	n = va_arg(args, unsigned int);
	if (n != 0)
		check = the_hexing(n, count, 0, x);
	else
	{
		check = 1;
		pf_putchar('0', count);
	}
	return (check);
}
