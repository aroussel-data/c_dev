/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 14:23:11 by marvin            #+#    #+#             */
/*   Updated: 2020/03/18 14:51:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int dest_length;

	i = 0;
	dest_length = ft_strlen(dest);

	while(src[i] != '\0')
	{
		dest[dest_length + i] = src[i];
		i++;
	}
	dest[dest_length + i] = '\0';
       return dest;	
}

int	main(void)
{
	char src[] = "abcabc";
	char dest[] = "iiiiii";
	printf("%s\n", ft_strcat(dest, src));
}

