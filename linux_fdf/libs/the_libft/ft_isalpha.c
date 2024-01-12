/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:30:29 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/27 15:03:46 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// int main()
// {
//     char test_cases[] = {'a', 'P', '7', '!', 'Z'};
//     int expected_results[] = {1, 1, 0, 0, 1};
//     int num_tests = sizeof(test_cases) / sizeof(char);
//     for (int i = 0; i < num_tests; i++) {
//         int result = ft_isalpha(test_cases[i]);
//             printf("%i", result);
//     }
// }