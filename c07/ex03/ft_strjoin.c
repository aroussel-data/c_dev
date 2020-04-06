/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 11:11:05 by marvin            #+#    #+#             */
/*   Updated: 2020/04/06 11:55:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		result++;
		i++;
	}
	return result;
}

int	ft_arraysize(int size, char **strs)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (i < size)
	{
		result = result + ft_strlen(strs[i]) + 1;
		i++;
	}
	return result;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int i;
	int j;
	int res_length;
	int res_size = ft_arraysize(size, strs);
        char *res;
	
	i = 0;
	if (size == 0)
	{
		res = (char *)malloc(1);
		res[0] = '\0';
		return res;
	}
	res = (char *)malloc(res_size);
	res_length = 0;
	while (i < size)  // iterate over each string in the array of strings
	{
		j = 0;
		while (j < ft_strlen(strs[i]))  //enter into each individual string
		{
			res[res_length + j] = strs[i][j];
			j++;
		}
		if (j == ft_strlen(strs[i]) && !(i == size - 1))
		{
			res[res_length + j] = *sep;
			res[res_length + j + 1] = '\0';
		}
		if (i == size - 1)
		{
			res[res_length + j] = '\0';
		}
		res_length = ft_strlen(res);
		i++;
	}
	return res;
}

int main(void)
{
	char *strs[3];
	char a[] = "abc";
	char b[] = "def";
	char c[] = "ghi";
	char sep = ',';

	strs[0] = a;
	strs[1] = b;
	strs[2] = c;
	printf("%s\n", ft_strjoin(3, strs, &sep));
}
