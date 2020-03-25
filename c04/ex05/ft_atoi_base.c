/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 09:56:50 by marvin            #+#    #+#             */
/*   Updated: 2020/03/25 17:49:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_char_index(char *str, char to_index)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_index)
		{
			return i;
		}
		i++;
	}
	return -1;
}

int	ft_pow(int x, int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	if (n % 2 == 0)
		return ft_pow(x * x, n / 2);
	return x * ft_pow(x * x, n / 2);
}

int	ft_strchar(char *str, char to_find)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find)
		{
			return 1;
		}
		i++;
	}
	return 0;
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

int	ft_atoi_base(char *str, char *base)
{
	int i;
	int j;
	char result[ft_strlen(str)];
	int num_dash;
	int final;

	i = 0;
	j = 0;
	num_dash = 0;
	final = 0;
	if (ft_strlen(base) < 2 || ft_base_check(base))
	{
		return 0;
	}
	while (str[i] != '\0')
	{
		if (str[i] == 45)
		{
			num_dash++;
		}
		if (ft_strchar(base, str[i]))
		{
			result[j] = str[i];
			j++;
		}
		result[j] = '\0';
		if (!(ft_strchar(base, str[i+1])) && j != 0)
		{
			int l;
			i = 0; 
			l = ft_strlen(result) - 1;
			while (result[i] != '\0')
			{
				final = final + ft_char_index(base, result[i]) * ft_pow(ft_strlen(base), l);
				l--;
				i++;
			}
			return result_checker(&final, &num_dash);
		}
		if (!(str[i] == 45 || str[i] == 43 || str[i]  == 32 || (ft_strchar(base, str[i]))))
		{
			return 0;
		}
		i++;
	}
}

int	main(void)
{
	//char str1[] = "  ---+--+1234a567";
	//char str2[] = "  ---+--+2147483648a567";
	printf("%d\n", ft_atoi_base("FFFFF", "0123456789ABCDEF"));
}
