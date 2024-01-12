/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:50:36 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/27 17:25:09 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*str_to_be_filled;

	str_to_be_filled = (unsigned char *) ptr;
	i = 0;
	while (i < num)
	{
		str_to_be_filled[i] = (unsigned char) value;
		i++;
	}
	return (ptr);
}

// int main() {
// 	char str[20] = "Hello, peolpe!";
// 	printf("Before memset: %s\n", str);
// 	ft_memset(str, 'a', 5);
// 	printf("After memset: %s\n", str);
// 	return 0;
// }