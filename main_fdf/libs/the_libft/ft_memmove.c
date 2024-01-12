/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:31:14 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/27 16:33:58 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	size_t			i;
	unsigned char	*destination;
	unsigned char	*source;

	if (!src && !dest)
		return (dest);
	destination = (unsigned char *)dest;
	source = (unsigned char *)src;
	i = num;
	if (source < destination)
	{
		while (i--)
		{
			destination[i] = source[i];
		}
		return (dest);
	}
	else
		ft_memcpy(dest, src, num);
	return (dest);
}

// int main() {
//     char str[] = "Hello, World!";
//     printf("Before memmove: %s\n", str);
//     char str2[] = "Hello, World!";
//     ft_memmove(str + 2, str + 4, 5);
//     printf("After memmove with mine: %s\n", str);
//     memmove(str2 + 2, str2 + 4, 5);
//     printf("After memmove standard: %s\n", str2);
//     return 0;
// }