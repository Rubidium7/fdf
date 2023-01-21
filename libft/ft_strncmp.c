/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:40:27 by nlonka            #+#    #+#             */
/*   Updated: 2022/11/08 14:58:29 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s3;
	unsigned char	*s4;

	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s3[i] == s4[i] && i < n && s3[i] != '\0' && s4[i] != '\0')
		i++;
	if (i == n && (s3[i] == '\0' || s4[i] == '\0'))
		return (0);
	if (i == n && s3[i - 1] == s4[i - 1])
		return (0);
	return (s3[i] - s4[i]);
}
