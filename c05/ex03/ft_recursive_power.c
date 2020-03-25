/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 18:50:35 by marvin            #+#    #+#             */
/*   Updated: 2020/03/25 18:51:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return 1;
	if (power == 1)
		return nb;
	if (power % 2 == 0)
		return ft_recursive_power(nb * nb, power / 2);
	return nb * ft_recursive_power(nb * nb, power / 2);
}
