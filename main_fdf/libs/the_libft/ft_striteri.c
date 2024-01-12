/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:46:32 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/20 22:31:47 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}

// void make_char_o(unsigned int i, char *c)
// {
//     printf("Char at %u is %c\n", i, *c);
// }
// int main()
// {
//     char str[] = "vika!";
//     ft_striteri(str, make_char_o);
// }