/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 12:27:47 by marvin            #+#    #+#             */
/*   Updated: 2020/03/17 15:06:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return dest;
}

int	main(void)
{
	char src[4] = "abc";
	char dest[] = "iiiiiiiiiiiiii";

	printf("before: %s\n", dest);
	printf("after: %s\n", ft_strncpy(dest, src, 2));

	for (int j = 0; j < 3; j++)
	{
		printf("%d", dest[j]);
	}
	printf("\n");
	
}
