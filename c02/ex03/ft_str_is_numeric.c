/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 15:51:37 by marvin            #+#    #+#             */
/*   Updated: 2020/03/17 16:05:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int i;
	int num_numeric;
	int num_non_numeric;

	i = 0;
	num_numeric = 0;
	num_non_numeric = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 48 && str[i] <= 57))
		{
			num_numeric++;
		}
		else
		{
			num_non_numeric++;
		}
		i++;
	}
	if (num_non_numeric)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
