/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:29:34 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/27 14:54:53 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == 32);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	i;

	sign = 1;
	result = 0;
	i = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

// int main()
// {
//     const char *str = "      ---------12345";
//     int result_ft = ft_atoi(str);
//     int result_standard = atoi(str);
//     printf("Input string: %s\n", str);
//     printf("my ft_atoi result: %d\n", result_ft);
//     printf("the atoi result: %d\n", result_standard);
//     if (result_ft == result_standard)
//         printf("same!!\n");
//     else
//         printf("different :(((\n");
// }