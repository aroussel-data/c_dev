/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 15:53:05 by marvin            #+#    #+#             */
/*   Updated: 2020/03/18 17:58:23 by marvin           ###   ########.fr       */
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

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int to_find_length;

	i = 0;
	j = 0;
	to_find_length = ft_strlen(to_find);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			j++;
			if (j == to_find_length)
			{
				return &str[i - (to_find_length - 1)];
			}
		}
		i++;
	}
	if (*to_find == '\0')
	{
		return str;
	}
	else
	{
		return NULL;
	}
}
