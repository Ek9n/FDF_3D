/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:56:45 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/27 16:50:07 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (count);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		start;
	size_t	finish;
	size_t	i;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !(split))
		return (NULL);
	start = -1;
	finish = 0;
	i = 0;
	while (finish <= ft_strlen(s))
	{
		if (s[finish] != c && start < 0)
			start = finish;
		else if ((s[finish] == c || finish == ft_strlen(s)) && start >= 0)
		{
			split[i++] = word_dup(s, start, finish);
			start = -1;
		}
		finish++;
	}
	split[i] = 0;
	return (split);
}

// int main()
// {
// 	const char *str = "Hello,World,Potato,Tomato,Chocolate";
// 	char **words = ft_split(str, ',');
// 	if (words)
// 	{
// 		for (int i = 0; words[i] != NULL; i++)
// 		{
// 			printf("%s\n", words[i]);
// 			free(words[i]);
// 		}
// 		free(words);
// 	}
// }