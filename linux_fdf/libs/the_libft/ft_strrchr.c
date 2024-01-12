/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:14:37 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/27 17:41:05 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if ((char)c == 0)
		return ((char *)(s + len));
	while (len)
	{
		if (s[len -1] == (char)c)
			return ((char *)(s + len - 1));
		len--;
	}
	return (NULL);
}

// int main() {
//     const char *str = "Hello, Woerlde!";
//     int ch = 'e';
//     char *result = ft_strrchr(str, ch);
//     if (result != NULL) {
//         printf("%s\n", result);
//     } else {
//         printf("'%c' not found in '%s'\n", ch, str);
//     }
// }