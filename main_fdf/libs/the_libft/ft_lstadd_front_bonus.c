/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:27:44 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/28 17:41:33 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}

// int main ()
// {
// 	t_list *a;
// 	t_list *b;
// 	a = ft_lstnew("a");
// 	b = ft_lstnew("b");
// 	ft_lstadd_front(&a, b);
// 	printf("this is B list: %s\n", b->content);
// 	printf("this is the next after B: %s\n", (b->next)->content);
// 	while (a)
// 	{
// 		printf("%s\n", a->content);
// 		a = a->next;
// 	}
// }