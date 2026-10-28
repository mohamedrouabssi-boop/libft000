/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouabss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 15:40:18 by mrouabss          #+#    #+#             */
/*   Updated: 2026/10/18 15:40:23 by mrouabss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
//int main ()
//{
//	t_list *first_head = ft_lstnew("mohamed" );
//	t_list *new_node = ft_lstnew("omhamedofpgtkdfkgcxljgpfigfd[g[pg[gf[]]]]");
//	ft_lstadd_front(&first_head, new_node);
//	while (first_head)
//	{
//		printf("%s", (char *)first_head->content);
//		first_head = first_head->next;
//	}
//}
