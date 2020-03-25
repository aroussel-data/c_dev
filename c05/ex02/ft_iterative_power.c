/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 18:46:25 by marvin            #+#    #+#             */
/*   Updated: 2020/03/25 19:24:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int init;

	init = nb;
	if (power < 0)
		return 0;
	if (power == 0)
		return 1;
	if (power == 1)
		return nb;
	if (power % 2 == 0)
	{
		while (power > 1)
		{
			nb = nb * nb;
			power = power / 2;
		}
		return nb;
	}
	if (power % 2)
	{
		while (power > 1)
		{
			nb = nb * nb;
			power = power / 2;
		}
		return init * nb;
	}
}

int	main(void)
{
	printf("%d\n", ft_iterative_power(2, 3));
}
