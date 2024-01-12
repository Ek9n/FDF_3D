/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:31:09 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/19 18:47:20 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	size_t			i;
	unsigned char	*dest_copy;
	unsigned char	*src_copy;

	if (!dest && !src)
		return (dest);
	dest_copy = (unsigned char *) dest;
	src_copy = (unsigned char *) src;
	i = 0;
	while (i < num)
	{
		dest_copy[i] = src_copy[i];
		i++;
	}
	return (dest);
}

// int main() {
//     char source[] = "Hello, World!";
//     char destination[20];
//     ft_memcpy(destination, source, sizeof(source));
//     printf("Source: %s\n", source);
//     printf("Destination: %s\n", destination);
//     return 0;
// }