/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:15:00 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/27 16:52:03 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			dest_size;
	size_t			src_size;
	unsigned int	i;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	i = 0;
	if (size == 0 && dest_size == 0)
		return (src_size);
	if (dest_size >= size)
		return (size + src_size);
	while (src[i] != '\0' && (i + dest_size) < size - 1)
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return ((dest_size + src_size));
}

// int main() {
//     char dest[] = "Hello, ";
//     const char *src = "world!!!";
// 	//size_t mine = ft_strlcat(dest, src, 19);
// 	size_t original = strlcat(dest, src, 19);
//     printf("Source: %s\n", src);
//     printf("Destination: %s\n", dest);
// 	//printf("Length mine: %zu\n", mine);
// 	printf("Length original: %zu\n", original);
// }