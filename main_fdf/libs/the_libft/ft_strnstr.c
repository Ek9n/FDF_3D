/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:15:22 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/27 16:52:52 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t size)
{
	size_t		needle_len;

	needle_len = ft_strlen(needle);
	if (*needle && size == 0)
		return (0);
	if (*needle == '\0')
		return ((char *)hay);
	while (*hay && size >= needle_len)
	{
		if (*hay == *needle && !ft_memcmp(hay, needle, needle_len))
			return ((char *)hay);
		hay++;
		size--;
	}
	return (NULL);
}

// int main()
// {
//     const char *haystack = "Hello, World!";
//     const char *needle = "";
//     size_t len = strlen(haystack);
//     char *result_ft = ft_strnstr(haystack, needle, len);
//     // int result_standard = strnstr(haystack, needle, len);
//     printf("Haystack: %s\n", haystack);
//     printf("Needle: %s\n", needle);
//     if (result_ft != NULL)
//     {
//         printf("ft_strnstr result: %s\n", result_ft);
//     }
//     else
//     {
//         printf("ft_strnstr result: Not found\n");
//     }
//     // if (result_standard != NULL)
//     // {
//     //     printf("strnstr result: %s\n", result_standard);
//     // }
//     // else
//     // {
//     //     printf("strnstr result: Not found\n");
//     // }
//     // if (result_ft == result_standard)
//     // {
//     //     printf("ft_strnstr and strnstr returned the same result.\n");
//     // }
//     // else
//     // {
//     //     printf("ft_strnstr and strnstr returned different results.\n");
//     // }
//     return 0;
// }