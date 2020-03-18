/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 18:33:55 by marvin            #+#    #+#             */
/*   Updated: 2020/03/18 19:09:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int i;
	int dest_length;

	i = 0;
	dest_length = ft_strlen(dest);

	while(i < size && src[i] != '\0')
	{
		dest[dest_length + i] = src[i];
		i++;
	}
	dest[dest_length + i] = '\0';
	return dest_length + i;
}
