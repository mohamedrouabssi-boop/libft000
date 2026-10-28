/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 10:43:54 by mrouabss          #+#    #+#             */
/*   Updated: 2026/10/13 12:10:51 by mrouabss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	n;
	size_t	len;

	len = 0;
	while (src[len])
	{
		len++;
	}
	i = 0;
	while (i < size && dst[i])
		i++;
	len += i;
	if (i == size)
		return (len);
	n = 0;
	while (src[n] && i < size - 1)
	{
		dst[i] = src[n];
		n++;
		i++;
	}
	dst[i] = '\0';
	return (len);
}
