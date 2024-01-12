/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:49:09 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/27 14:46:01 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	length_of_num(long n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		length++;
	}
	while (n > 0)
	{
		length++;
		n /= 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	long	long_n;

	long_n = (long)n;
	len = length_of_num(long_n);
	result = (char *) malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len--] = '\0';
	if (long_n == 0)
		result[0] = '0';
	if (long_n < 0)
	{
		long_n = -long_n;
		result[0] = '-';
	}
	while (long_n > 0)
	{
		result[len--] = (long_n % 10) + 48;
		long_n /= 10;
	}
	return (result);
}

// int main(){
// 	int a = 5411115;
//     printf("Decimal value = %s\n", ft_itoa(a));
//     return 0;
// }