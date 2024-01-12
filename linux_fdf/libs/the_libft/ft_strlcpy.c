/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:15:05 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/27 16:52:17 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}

// int main() {
//     char dest[20];
//     const char *src1 = "Hello, world!";
//     size_t len1 = strlcpy(dest, src1, 4);
//     printf("Source: %s\n", src1);
//     printf("Destination: %s\n", dest);
//     printf("Length: %zu\n\n", len1);
//     return 0;
// }