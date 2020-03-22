/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 11:17:10 by marvin            #+#    #+#             */
/*   Updated: 2020/03/22 17:14:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

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
		u_nb = (unsigned int)((nb - nb) - nb);
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

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

int	ft_base_check(char *str)
{
	int i;
	int flag;
	int j;

	i = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 45 || str[i] == 43)
		{
			flag = 1;
		}
		i++;
	}

	i = 0;
	while (i < ft_strlen(str) - 1)
	{
		j = i + 1;
		while (j < ft_strlen(str))
		{
			if (str[i] == str[j])
			{
				flag = 1;
			}
			j++;
		}
		i++;
	}

	return flag;
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int n;
	
	if (ft_strlen(base) < 2 || ft_base_check(base))
	{
		write(1, "", 1);
	}

	if (nbr == 0)
	{
		write(1, &base[0], 1);
	}
	if (nbr > 0)
	{
		if (!(nbr / ft_strlen(base) == 0))
		{
			ft_putnbr_base(nbr / ft_strlen(base), base);
		}
		write(1, &base[nbr % ft_strlen(base)], 1);
	}
	if (nbr < 0)
	{
		if (ft_strlen(base) == 10)
		{
			ft_putnbr(nbr);
		}

		if (ft_strlen(base) != 10)
		{
			n = nbr; 
			if (n > 0)
			{
				ft_putnbr_base(n / ft_strlen(base), base);
				write(1, &base[n % ft_strlen(base)], 1);
			}
		}
	}
}

int	main(void)
{
	int nbr = -23647;
	char base[] = "01";
	ft_putnbr_base(nbr, base);
}
