/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:12:07 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/27 16:15:05 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst && f)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}

// void f(void *some_input)
// {
// 	while (*(char *)some_input)
// 	{
// 		--*(char *)some_input;
// 		some_input++;
// 	}
// }

// int main (void)
// {
// 	char str[4] = "www";
// 	t_list	*head = ft_lstnew(str);
// 	printf("%s\n", head->content);
// 	ft_lstiter(head, f);
// 	printf("%s\n", head->content);
// }