/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 11:03:00 by marvin            #+#    #+#             */
/*   Updated: 2020/03/20 19:54:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int u_nb;
	
	if (nb < 0)
	{
		ft_putchar('-');
		u_nb = (nb - nb) - nb;
		ft_putnbr(u_nb / 10);
		ft_putchar((u_nb % 10) + '0');
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	if (nb < 10 && nb >=0)
	{
		ft_putchar((nb % 10) + '0');
	}
}

int	main(void)
{
	int a = -42;
	ft_putnbr(a);
}
