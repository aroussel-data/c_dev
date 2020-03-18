/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 14:54:01 by marvin            #+#    #+#             */
/*   Updated: 2020/03/18 15:51:12 by marvin           ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int i;
	int dest_length;

	i = 0;
	dest_length = ft_strlen(dest);

	while(i < nb && src[i] != '\0')
	{
		dest[dest_length + i] = src[i];
		i++;
	}
	dest[dest_length + i] = '\0';
	return dest;	
}
