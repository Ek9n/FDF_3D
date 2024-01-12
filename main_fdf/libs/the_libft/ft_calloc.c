/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshcherb <vshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:11:23 by vshcherb          #+#    #+#             */
/*   Updated: 2023/05/19 00:06:47 by vshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elem, size_t elem_size)
{
	void	*result;

	result = malloc(num_elem * elem_size);
	if (result)
		return (ft_memset(result, 0, num_elem * elem_size));
	return (result);
}
