/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 11:55:37 by marvin            #+#    #+#             */
/*   Updated: 2020/04/02 14:28:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_ascii_sum(char *str)
{
	int i;
	int total;

	i = 0;
	total = 0;
	while (str[i] != '\0')
	{
		total = total + str[i];
		i++;
	}
	return total;
}

void	ft_putstr(char *str)
{
	int i;
        
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int i;
	int t;
	int j;
	char *temp;

	i = 1;
	temp = 0;
	while (i < (argc - 1))
	{
		t = 1;
		while (t < (argc - 1))
		{
			if (ft_ascii_sum(argv[t]) > ft_ascii_sum(argv[t+1]))
			{
				temp = argv[t];
				argv[t] = argv[t+1];
				argv[t+1] = temp;
			}
			t++;
		}
		i++;
	}
	
	j = 1;
	while (j < argc)
	{
		ft_putstr(argv[j]);
		j++;
	}
}
