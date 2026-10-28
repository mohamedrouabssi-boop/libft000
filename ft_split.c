/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 11:02:56 by mrouabss          #+#    #+#             */
/*   Updated: 2026/10/16 12:01:28 by mrouabss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	ft_free_all(char **dst, size_t n)
{
	while (n > 0)
	{
		n--;
		free(dst[n]);
	}
	free(dst);
}

static char	*ft_next_word(char const *s, char c, size_t *i)
{
	size_t	start;

	while (s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	return (ft_substr(s, start, *i - start));
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	words;
	size_t	n;
	size_t	i;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	dst = malloc((words + 1) * sizeof(char *));
	if (!dst)
		return (NULL);
	n = 0;
	i = 0;
	while (n < words)
	{
		dst[n] = ft_next_word(s, c, &i);
		if (!dst[n])
		{
			ft_free_all(dst, n);
			return (NULL);
		}
		n++;
	}
	dst[n] = NULL;
	return (dst);
}
