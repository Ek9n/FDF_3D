/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:10:59 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/27 16:59:42 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int) ft_strlen(s))
		return (ft_calloc(1, 1));
	while (s[start + i] && i < len)
		i++;
	sub = (char *) malloc((i + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}

// int main() {
//     const char *str = "Hello, World!";
//     unsigned int start = 2;
//     size_t len = 5;

//     char *substr = ft_substr(str, start, len);
//     if (substr != NULL) {
//         printf("Substring: '%s'\n", substr);
//         free(substr);
//     } else {
//         printf("Failed to extract the substring.\n");
//     }
// }