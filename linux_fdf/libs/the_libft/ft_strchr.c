/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:14:53 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/21 00:48:28 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

// int main()
// {
// 	const char *str = "Hello, World!";
// 	int c = 'o';
// 	char *result_ft = ft_strchr(str, c);
// 	char *result_standard = strchr(str, c);
// 	if (result_ft != result_standard)
// 	{
// 		printf("Mismatch\n");
// 	}
// 	else if (result_ft == NULL)
// 	{
// 		printf("Both ft_strrchr and strrchr returned NULL.\n");
// 	}
// 	else
// 	{
// 		printf("Match! %s\n", result_ft);
// 	}
// 	return 0;
// }