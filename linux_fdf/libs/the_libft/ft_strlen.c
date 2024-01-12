/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:15:10 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/20 22:30:06 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (*str++)
		length++;
	return (length);
}

// int main() {
//     char str1[] = "Hello, world!";
//     char str2[] = "";
//     char str3[] = "Potato";
//     printf("Length of '%s': %lu\n", str1, ft_strlen(str1));
//     printf("Length of '%s': %lu\n", str2, ft_strlen(str2));
//     printf("Length of '%s': %lu\n", str3, ft_strlen(str3));
//     return 0;
// }