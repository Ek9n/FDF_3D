/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:30:11 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/27 15:03:34 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

// int main() {
//     char test_cases[] = {'0', '9', '5', 'a', '\n'};
//     int expected_results[] = {1, 1, 1, 1, 0};
//     int num_tests = sizeof(test_cases) / sizeof(char);
//     for (int i = 0; i < num_tests; i++) {
//         int result = ft_isalnum(test_cases[i]);
//             printf("%d\n", result);
//     }
// }