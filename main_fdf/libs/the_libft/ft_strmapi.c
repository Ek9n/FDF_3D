/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:59:16 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/27 13:51:19 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// char make_char_o(unsigned int index, char c) {
//     return index % 2 == 0 ? c + 1 : c + 2;
// }
// int main() {
//     const char *s = "abc";
//     char *result = ft_strmapi(s, make_char_o);
//     if (result != NULL) {
//         printf("Original: %s\n", s);
//         printf("Result: %s\n", result);
//         free(result);
//     } else {
//         printf("Failed!\n");
//     }
// }