/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:05:01 by mrouabss          #+#    #+#             */
/*   Updated: 2026/10/19 13:05:06 by mrouabss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*src;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		src = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = src;
	}
}
