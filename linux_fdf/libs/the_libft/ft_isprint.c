/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:30:47 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/27 15:07:19 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// int main() {
//     char test_cases[] = {'a', 'P', ' ', '!', '7', '\n'};
//     int expected_results[] = {1, 1, 1, 1, 1, 0};
//     int num_tests = sizeof(test_cases) / sizeof(char);
//     for (int i = 0; i < num_tests; i++) {
//         int result = ft_isprint((int)test_cases[i]);
//         if (result == expected_results[i]) {
//             printf("Test case %d passed\n", i+1);
//         } else {
//             printf("exp %d, got %d\n", i+1, expected_results[i], result);
//         }
//     }
// }