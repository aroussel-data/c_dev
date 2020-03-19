/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 13:28:37 by marvin            #+#    #+#             */
/*   Updated: 2020/03/19 18:41:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_str_is_printable(char c)
{
	if (c >= 32 && c <= 126)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void	ft_convert_nonprint_to_hex(int n)
{
	char hex[] = "0123456789abcdef";

	if (n / 16 == 0)
	{
		write(1, "0", 1);
		write(1, &hex[n], 1);
	}
	else if (n / 16 == 1)
	{	
		write(1, "1", 1);
		write(1, &hex[n % 16], 1);
	}
	else
	{
		write(1, "\0", 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int i;
	int j = 0;

	i = 0;
	while(str[i] != '\0')
	{
		if ((ft_str_is_printable(str[i])))
		{
			write(1, &str[i], 1);
		}
		else if (!(ft_str_is_printable(str[i])))
		{
			write(1, "\\", 1);
			ft_convert_nonprint_to_hex((int)str[i]);
		}
		i++;
	}
}

int	main(void)
{
	char str[] = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(str);
}
