/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 13:40:27 by marvin            #+#    #+#             */
/*   Updated: 2020/03/18 13:55:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	// like strcmp but we only compare the first n bytes of the two strings, i.e. while i < n
	int i;
	int s1_result;
	int s2_result;

	i = 0;
	s1_result = 0;
	s2_result = 0;

	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
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
	char str1[] = "abc";
	char str2[] = "abc";
	printf("%d\n", ft_strncmp(str1, str2, 2));
}
