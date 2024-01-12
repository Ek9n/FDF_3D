/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:15:18 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/19 20:47:43 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	while (size > 0 && *str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
		size--;
	}
	if (size == 0)
		return (0);
	else
		return ((unsigned char)(*str1) - (unsigned char)(*str2));
}

// int main()
// {
//     const char *str1 = "Hello, world!";
//     const char *str2 = "Hallo, folks!";
//     size_t n = 17;

//     int result_ft = ft_strncmp(str1, str2, n);
//     int result_standard = strncmp(str1, str2, n);

//     if (result_ft < result_standard)
//     {
//         printf("ft_strncmp returned a smaller value than strncmp.\n");
//     }
//     else if (result_ft > result_standard)
//     {
//         printf("ft_strncmp returned a larger value than strncmp.\n");
//     }
//     else
//     {
//         printf("ft_strncmp and strncmp returned the same value.\n");
//     }

//     return 0;
// }