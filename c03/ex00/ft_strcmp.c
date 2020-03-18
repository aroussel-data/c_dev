/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 21:28:17 by marvin            #+#    #+#             */
/*   Updated: 2020/03/18 13:56:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int i;
	int s1_result;
	int s2_result;

	i = 0;
	s1_result = 0;
	s2_result = 0;

	while (s1[i] != '\0' || s2[i] != '\0')
	{
		s1_result = s1_result + s1[i];
		s2_result = s2_result + s2[i];
		i++;
	}

	if (s1_result == s2_result)
	{
		return 0;
	}
	else if (s1_result < s2_result)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

int	main(void)
{
	char str1[] = "abc";  //this should be greater than str2, i.e. return 1.
	char str2[] = "ABC";
	
	printf("%d", ft_strcmp(str1, str2));
}
