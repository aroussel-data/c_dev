/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 18:03:17 by marvin            #+#    #+#             */
/*   Updated: 2020/03/25 18:43:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return 1;
	if (nb > 1)
		return nb * ft_recursive_factorial(nb - 1);
	if (nb < 0)
		return nb * ft_recursive_factorial(nb + 1);
}

int	main(void)
{
	printf("%d\n", ft_recursive_factorial(19));
}
