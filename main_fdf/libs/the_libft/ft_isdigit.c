/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:30:43 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/27 15:04:55 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// int main() {
//     char test_cases[] = {'0', '9', '5', 'a', 'Z'};
//     int expected_results[] = {1, 1, 1, 0, 0};
//     int num_tests = sizeof(test_cases) / sizeof(char);
//     for (int i = 0; i < num_tests; i++) {
//         int result = ft_isdigit(test_cases[i]);
//             printf("%d\n", result);
//     }
// }