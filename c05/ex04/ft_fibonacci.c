/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 09:11:32 by marvin            #+#    #+#             */
/*   Updated: 2020/03/26 13:37:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index == 0)
		return 0;
	if (index == 1)
		return index;
	if (index < 0)
		return -1;
	if (index > 1)
		return ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
}

int	main(void)
{
	printf("%d", ft_fibonacci(9));
}
