/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:31:04 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/27 16:31:52 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t size)
{
	const unsigned char	*byte_ptr1;
	const unsigned char	*byte_ptr2;

	byte_ptr1 = ptr1;
	byte_ptr2 = ptr2;
	while (size > 0)
	{
		if (*byte_ptr1 != *byte_ptr2)
			return (*byte_ptr1 - *byte_ptr2);
		byte_ptr1++;
		byte_ptr2++;
		size--;
	}
	return (0);
}

// int main()
// {
//     unsigned char block1[] = {0, 2, 3, 3};
//     unsigned char block2[] = {0, 2, 3, 3, 3};
//     size_t num = 0;
//     int result_ft = ft_memcmp(block1, block2, num);
//     int result_standard = memcmp(block1, block2, num);
//     if (result_ft < result_standard)
//         printf("ft_memcmp returned a smaller value than memcmp.\n");
//     else if (result_ft > result_standard)
//         printf("ft_memcmp returned a larger value than memcmp.\n");
//     else
//         printf("ft_memcmp and memcmp returned the same value.\n");
// }