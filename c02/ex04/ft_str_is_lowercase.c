/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:07:21 by marvin            #+#    #+#             */
/*   Updated: 2020/03/17 16:11:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int i;
	int num_lower;
	int num_non_lower;

	i = 0;
	num_lower = 0;
	num_non_lower = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 97 && str[i] <= 122))
		{
			num_lower++;
		}
		else
		{
			num_non_lower++;
		}
		i++;
	}
	if (num_non_lower)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
