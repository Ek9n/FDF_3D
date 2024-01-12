/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:12:39 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/21 00:46:37 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1) - 1;
	while (s1[i] && ft_strrchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}

// int main()
// {
// 	const char *s1 = "////Hello, World!////";
// 	const char *set = "//";
// 	char *trimmed = ft_strtrim(s1, set);
// 	if (trimmed != NULL)
// 	{
// 		printf("Trimmed string: '%s'\n", trimmed);
// 		free(trimmed);
// 	}
// 	else
// 	{
// 		printf("Failed to trim the string.\n");
// 	}
// 	return 0;
// }