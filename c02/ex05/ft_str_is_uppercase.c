/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:14:46 by marvin            #+#    #+#             */
/*   Updated: 2020/03/17 16:23:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int i;
	int num_upper;
	int num_non_upper;

	i = 0;
	num_upper = 0;
	num_non_upper = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 65 && str[i] <= 90))
		{
			num_upper++;
		}
		else
		{
			num_non_upper++;
		}
		i++;
	}
	if (num_non_upper)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
