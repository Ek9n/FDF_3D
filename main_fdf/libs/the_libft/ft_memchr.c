/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:30:57 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/20 22:16:05 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t size)
{
	const unsigned char	*byte_ptr;

	byte_ptr = ptr;
	while (size > 0)
	{
		if (*byte_ptr == (unsigned char)c)
			return ((void *)byte_ptr);
		byte_ptr++;
		size--;
	}
	return (NULL);
}

// int main()
// {
//     const char *str = "Hello, world!";
//     char ch = 'l';
//     size_t num = strlen(str);
//     void *result_ft = ft_memchr(str, ch, num);
//     void *result_standard = memchr(str, ch, num);
//     if (result_ft != result_standard)
//         printf("Mismatch! :(\n");
//     else if (result_ft == NULL)
//         printf("Both ft_memchr and memchr returned NULL.\n");
//     else
//         printf("Match! %s\n", (char *)result_ft);
// }