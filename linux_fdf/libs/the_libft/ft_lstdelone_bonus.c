/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:29:58 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/27 16:13:31 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}

// void delete(void *content)
// {
//     free(content);
// }

// int main()
// {
//     char *str = malloc(2);
//     char *str2 = malloc(2);
//     *str = 'A';
//     *str2 = 'B';
//     t_list *a = ft_lstnew(str);
//     t_list *b = ft_lstnew(str2);

//     ft_lstadd_back(&a, b);
//     printf("%s\n", a->content);
//     printf("%s\n", b->content);

//     ft_lstdelone(a, &delete);
//     printf("%s\n", a->content);
//     printf("%p\n", a->next);
// }