/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 14:33:34 by marvin            #+#    #+#             */
/*   Updated: 2020/04/02 17:18:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strsize(char *str)
{
	int i;
	int total;

	i = 0;
	total = 1;
	while(str[i] != '\0')
	{
		total++;
		i++;
	}
	return total;
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

char	*ft_strdup(char *src)
{
	char *str;

	str = malloc(ft_strsize(src));
	ft_strcpy(str, src);
	return str;
}

int	main(void)
{
	char *my_string = ft_strdup("test");
	printf("%s\n", my_string);
	free(my_string);
}
