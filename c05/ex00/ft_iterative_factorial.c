/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 17:39:00 by marvin            #+#    #+#             */
/*   Updated: 2020/03/23 15:49:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int i;

	i = 0;
	if (nb < -1)
	{
		i = nb;
		while (i < -1)
		{
			nb *= (i + 1);
			i++;
		}
	}
	else if (nb > 1)
	{
		i = nb;
		while (i > 1)
		{
			nb *= (i - 1);
			i--;
		}
	}
	else if (nb == 0)
	{
		return 1;
	}
	
	return nb;
}

int	main(void)
{
	printf("%d", ft_iterative_factorial(0));
}
