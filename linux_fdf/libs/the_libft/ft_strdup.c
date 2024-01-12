/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:11:07 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/21 00:43:32 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t		length;
	char		*dup;

	length = ft_strlen(str) + 1;
	dup = (char *)malloc(length);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, str, length);
	return (dup);
}

// int main()
// {
//     const char *original = "Helsdsdadadawdwlo!";
//     char *duplicate_ft = ft_strdup(original);
//     char *duplicate_standard = strdup(original);
//     printf("Original string: %s\n", original);
//     printf("ft_strdup result: %s\n", duplicate_ft);
//     printf("strdup result: %s\n", duplicate_standard);
//     if (strcmp(duplicate_ft, duplicate_standard) == 0)
//     {
//         printf("same result.\n");
//     }
//     else
//     {
//         printf("different results.\n");
//     }
//     free(duplicate_ft);
//     free(duplicate_standard);
//     return 0;
// }