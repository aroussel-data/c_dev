/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 17:39:00 by marvin            #+#    #+#             */
/*   Updated: 2020/03/22 19:00:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int i;

	i = nb;
	while (i > 1)
	{
		nb *= (i - 1);
		i--;
	}
	return nb;
}

int	main(void)
{
	printf("%d", ft_iterative_factorial(4));
}
