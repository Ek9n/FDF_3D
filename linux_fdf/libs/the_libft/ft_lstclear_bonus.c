/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:52:44 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/26 22:13:25 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst && del)
	{
		while (*lst)
		{
			temp = *lst;
			*lst = (*lst)->next;
			ft_lstdelone(temp, del);
		}
	}
}

// void del(void *content)
// {
// 	free(content);
// }

// int main()
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
// 	//ft_lstclear(&node1, del);
// 	printf("Cleared list: ");
// 	current = node1;
// 	while (current)
// 	{
// 		printf("%d ", current->content);
// 		current = current->next;
// 	}
// 	printf("\n");
// }