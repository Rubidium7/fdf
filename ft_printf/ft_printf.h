/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:13:27 by nlonka            #+#    #+#             */
/*   Updated: 2022/11/27 13:23:56 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

void	pf_put_ung(unsigned long long nb, int *count);
void	pf_putnbr(long long nb, int *count);
void	pf_putchar(unsigned char c, int *count);
int		the_hexing(unsigned long long n, int *count, int loca, int x);
int		hexize(unsigned long long n);
int		ft_printf(const char *format, ...);
int		the_charade(int *count, va_list args, int *i);
int		string_it(int *count, va_list args, int *i);
int		mr_pointy(int *count, va_list args, int *i);
int		inting(int *count, va_list args, int *i);
int		the_unsung(int *count, va_list args, int *i);
int		hexer(char const c, int *count, va_list args, int *i);

#endif
