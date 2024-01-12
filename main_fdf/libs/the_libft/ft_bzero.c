/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:30:05 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/27 14:57:37 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t num)
{
	ft_memset(ptr, 0, num);
}

// int main() {
// 	char str[20] = "Do u like C?";
// 	printf("Before bzero: %s\n", str);
// 	ft_bzero(str, sizeof(str));
// 	printf("After bzero: %s\n", str);
// }