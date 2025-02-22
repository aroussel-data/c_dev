/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 19:29:52 by marvin            #+#    #+#             */
/*   Updated: 2020/03/20 13:18:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	result_checker(int *result, int *num_dash)
{
	if (*result < 0 && *num_dash % 2)
	{
		return *result;
	}
	else if (*result > 0 && *num_dash % 2)
	{
		return -(*result);
	}
	else
	{
		return *result;
	}
}

int	ft_atoi(char *str)
{
	int i;
	int result;
	int num_dash;

	i = 0;
	result = 0;
	num_dash = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 45)
		{
			num_dash++;
		}

		if (str[i] >= 48 && str[i] <= 57)
		{
			result = result * 10 + str[i] - '0';	
		}

		if (!(str[i] >= 48 && str[i] <= 57) && result != 0)
		{
			return result_checker(&result, &num_dash);
		}
		i++;
	}
	return result_checker(&result, &num_dash);
}

int	main(void)
{
	char str1[] = "  ---+--+1234a567";
	char str2[] = "  ---+--+2147483648a567";
	printf("%d\n", ft_atoi(str1));
	printf("%d\n", ft_atoi(str2));
}
