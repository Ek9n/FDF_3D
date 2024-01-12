/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:19:56 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/28 15:52:17 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	new_lst = NULL;
	if (lst && f)
	{
		while (lst)
		{
			new_node = ft_lstnew(f(lst->content));
			if (!new_node)
			{
				ft_lstclear(&new_lst, del);
				return (NULL);
			}
			ft_lstadd_back(&new_lst, new_node);
			lst = lst->next;
		}
	}
	return (new_lst);
}

// void *f(void *content)
// {
// 	if (1)
// 		return (content);
// 	return (0);
// }

// void del(void *content)
// {
// 	(void) content;
// }

// int main ()
// {
// 	t_list *node1 = malloc(sizeof(t_list));
// 	node1->content = 1;
// 	t_list *node2 = malloc(sizeof(t_list));
// 	node2->content = 2;
// 	t_list *node3 = malloc(sizeof(t_list));
// 	node3->content = 3;
// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = 0;
// 	printf("Initial list: ");
// 	t_list *current = node1;
// 	while (current)
// 	{
// 		printf("%d ", current->content);
// 		current = current->next;
// 	}
// 	printf("\n");
// 	t_list *tmp = ft_lstmap(node1, f, del);
// 	while (tmp)
// 	{
// 		printf("%d\n", tmp->content);
// 		tmp = tmp->next;
// 	}
// }