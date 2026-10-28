/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 18:46:17 by mrouabss          #+#    #+#             */
/*   Updated: 2026/10/15 09:33:54 by mrouabss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_dst;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len_dst = len_s1 + len_s2;
	dst = malloc(len_dst + 1);
	if (!dst)
		return (NULL);
	ft_memcpy(dst, s1, len_s1);
	ft_memcpy(dst + len_s1, s2, len_s2 + 1);
	return (dst);
}
