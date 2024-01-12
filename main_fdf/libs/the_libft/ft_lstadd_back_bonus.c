/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:08:36 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/27 16:00:23 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (new)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}

// int main ()
// {
// 	t_list *a;
// 	t_list *b;
// 	a = ft_lstnew("a");
// 	b = ft_lstnew("b");
// 	ft_lstadd_back(&a, b);
// 	printf("%s\n", (a->next)->content);
// }