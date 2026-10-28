/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 19:56:46 by mrouabss          #+#    #+#             */
/*   Updated: 2026/10/28 14:20:46 by mrouabss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_len_dst(long n2)
{
	int	len_dst;

	len_dst = 0;
	while (n2 >= 10)
	{
		n2 = n2 / 10;
		len_dst++;
	}
	return (len_dst);
}

char	*ft_malloc(int len_dst)
{
	char	*dst;

	dst = malloc(len_dst + 2);
	if (!dst)
		return (NULL);
	dst[len_dst + 1] = '\0';
	return (dst);
}

char	*ft_itoa(int n)
{
	char	*dst;
	long	nb;
	int		len_dst;

	nb = n;
	if (n < 0)
		nb = -nb;
	len_dst = ft_len_dst(nb);
	if (n < 0)
		len_dst++;
	dst = ft_malloc(len_dst);
	if (!dst)
		return (NULL);
	if (n < 0)
		dst[0] = '-';
	while (nb >= 10)
	{
		dst[len_dst] = nb % 10 + '0';
		nb = nb / 10;
		len_dst--;
	}
	dst[len_dst] = nb + '0';
	return (dst);
}
