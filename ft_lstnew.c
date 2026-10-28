/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 14:27:56 by mrouabss          #+#    #+#             */
/*   Updated: 2026/10/18 14:28:00 by mrouabss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*memorey_list;

	memorey_list = malloc(sizeof(t_list));
	if (!memorey_list)
		return (NULL);
	memorey_list->content = content;
	memorey_list->next = NULL;
	return (memorey_list);
}
//int main()
//{
//	t_list	*dst;
//	dst = ft_lstnew("hello world");
//	printf("the value: %s\n", (char *)dst->content);
//	printf("the add: %p\n", dst->next);
//	free(dst);
//}
